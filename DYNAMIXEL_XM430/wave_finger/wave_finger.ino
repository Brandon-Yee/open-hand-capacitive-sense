/* Dynamixel Increment Position 
 *  written by Brandon Yee, 2020
 *  for testing OpenHand Model 0
 *  using the XM430 with OpenCM9.04
 */

#include <DynamixelWorkbench.h>

#if defined(__OPENCM904__)
  #define DEVICE_NAME "3" //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
  #define DEVICE_NAME ""
#endif   

DynamixelWorkbench dxl_wb;



// Settings
#define DXL_BUS_SERIAL3 3
#define BAUDRATE  57600
#define DXL_ID    1

// Configuration
#define INCR    10
#define PERIOD  500

// Control Addresses
#define CTRL_GOAL_POS 116
#define CTRL_PRES_POS 132

void setup() {
  Serial.begin(57600);
  dxl_wb.jointMode(DXL_ID);
  while(!Serial); 
  Serial.println("Starting...");

  bool result = false;
  
  uint16_t model_number = 1020;
  //model_number = dxl_wb.getModelNumber(DXL_ID);
  Serial.print("Model Number: ");
  Serial.println(model_number);
  
  if (!dxl_wb.init(DEVICE_NAME, BAUDRATE))
  {
    Serial.println("Failed to init");
  }
  else
  {
    Serial.print("Succeeded to init : ");
    Serial.println(BAUDRATE);  
  }
  
  result = dxl_wb.ping(DXL_ID, &model_number);
  if (result == false)
  {
    Serial.println("Failed to ping");
  }
  else
  {
    Serial.println("Succeeded to ping");
    Serial.print("id : ");
    Serial.print(DXL_ID);
    Serial.print(" model_number : ");
    Serial.println(model_number);
  }

  result = dxl_wb.itemWrite(DXL_ID, "LED", 1);
  if (result == false)
  {
    Serial.println("Failed to LED On");
  }
  else
  {
    Serial.println("Succeed to LED On");
  }

  int32_t get_data = 0;
  result = dxl_wb.itemRead(DXL_ID, "Present_Position", &get_data);
  if (result == false)
  {
    Serial.println("Failed to get present position");
  }
  else
  {
    Serial.print("Succeed to get present position(value : ");
    Serial.print(get_data);
    Serial.println(")");
  }
  dxl_wb.torqueOn(DXL_ID);
}

int32_t present_pos;
int32_t new_goal_pos;
int32_t goal_pos = 1350;
bool flex = true;

void loop() {
  if (flex) {
    new_goal_pos = goal_pos + INCR; 
  } else {
    new_goal_pos = goal_pos - INCR;
  }
  dxl_wb.itemWrite(DXL_ID, "Goal_Position", new_goal_pos);
  goal_pos = new_goal_pos;
  if (goal_pos > 2500) {
    flex = false;
  } else if (goal_pos < 1400) {
    flex = true;
  }
  delay(PERIOD);
  bool result = dxl_wb.itemRead(DXL_ID, "Present_Position", &present_pos);
  if (result) {
    Serial.println(present_pos);
  }
}
