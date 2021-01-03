#include <DS3231.h>

int Relay1 = 4;//Front
int Relay2 = 5;//Back

DS3231  rtc(SDA, SCL);
Time t;


//******************************************************
const int Front_OnHour1 = 06;
const int Front_OnMin1 = 00;
const int Front_OffHour1 = 06;//Front
const int Front_OffMin1 = 05;

const int Front_OnHour2 = 18;
const int Front_OnMin2 = 00;
const int Front_OffHour2 = 18;//Front
const int Front_OffMin2 = 05;

//******************************************************
const int Back_OnHour1 = 06;
const int Back_OnMin1 = 00;
const int Back_OffHour1 = 06;//Back
const int Back_OffMin1 = 05;

const int Back_OnHour2 = 18;
const int Back_OnMin2 = 00;
const int Back_OffHour2 = 18;//Back
const int Back_OffMin2 = 05;

//******************************************************



void setup() {
  Serial.begin(115200);
  rtc.begin();
  
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  
  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);
  
}

//******************************************************
void Front()//Front
{
  if ((t.hour >= Front_OnHour1 && t.hour <= Front_OffHour1) && (t.min >= Front_OnMin1 && t.min <= Front_OffMin1))

  {
    digitalWrite(Relay1, LOW);
    Serial.println("Relay 1  ON  ");
  }
  
  else if ((t.hour >= Front_OnHour2 && t.hour <= Front_OffHour2) && (t.min >= Front_OnMin2 && t.min <= Front_OffMin2))

  {
    digitalWrite(Relay1, LOW);
    Serial.println("Relay 1  ON ");
  }
  
  else  
  {
    digitalWrite(Relay1, HIGH);
    Serial.println("Relay 1  OFF ");
  }

}

//******************************************************

void Back()//Back
{
  if ((t.hour >= Back_OnHour1 && t.hour <= Back_OffHour1) && (t.min >= Back_OnMin1 && t.min <= Back_OffMin1))

  {
    digitalWrite(Relay2, LOW);
    Serial.println("Relay 2  ON ");
  }

  else if ((t.hour >= Back_OnHour2 && t.hour <= Back_OffHour2) && (t.min >= Back_OnMin2 && t.min <= Back_OffMin2))

  {
    digitalWrite(Relay2, LOW);
    Serial.println("Relay 2  ON ");
  }

  else  
  {
    digitalWrite(Relay2, HIGH);
    Serial.println("Relay 2  OFF ");
  }

}

//******************************************************


void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.println(" ");
  delay (1000);
  
  Front();
  Back();

}
