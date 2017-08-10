class Sensors {
  public:
    virtual void setAnalogPin(int PinNo) = 0;
    virtual void setHyd_Name(const String& HydName)=0;
    virtual int getAnalogPin() = 0;
    virtual String& getHyd_Name()=0;
};

class PHSensor : public Sensors {
  private:
  int analogPin;
  String Hyd_Name;
  public:
    virtual void setAnalogPin(int PinNo) {
      analogPin = PinNo;
      Serial.println("PHSensor called with analogPin "+ PinNo);
    }
    virtual void setHyd_Name(const String& HydName)
    {
        //Hyd_Name = HydName;
        Hyd_Name = "PH";
    }
    virtual int getAnalogPin()
    {
        return analogPin;
    }
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;

class ConductivitySensor : public Sensors {
   private:
   int analogPin;
   String Hyd_Name;
  public:
    virtual void setAnalogPin(int PinNo) {
      analogPin = PinNo;
      Serial.println("ConductivitySensor called with analogPin "+ PinNo);
    }
    virtual void setHyd_Name(const String& HydName)
    {
        //Hyd_Name = HydName;
        Hyd_Name = "Cond";
    }
    virtual int getAnalogPin()
    {
        return analogPin;
    }
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
};

class WaterTemperatureSensor : public Sensors {
  private:
   int analogPin;
   String Hyd_Name;
  public:
    virtual void setAnalogPin(int PinNo) {
      analogPin = PinNo;
      Serial.println("WaterTemperatureSensor called");
    }
    virtual void setHyd_Name(const String& HydName)
    {
        //Hyd_Name = HydName;
        Hyd_Name = "Temp";
    }
    virtual int getAnalogPin()
    {
        return analogPin;
    }
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 

};

class LightSensor : public Sensors {
   private:
   int analogPin;
   String Hyd_Name;
  public:
    virtual void setAnalogPin(int PinNo) {
      analogPin = PinNo;
      Serial.println("LightSensor called ");
    }
    virtual void setHyd_Name(const String& HydName)
    {
        //Hyd_Name = HydName;
        Hyd_Name = "Light";
    }
    virtual int getAnalogPin()
    {
        return analogPin;
    }
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 

};
