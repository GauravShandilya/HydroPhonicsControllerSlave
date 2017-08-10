class ActuatorsOutPut {
  public:
    virtual void setDigitalOutputPin(int PinNo) = 0;
    virtual void setHyd_Name(const String& HydName)=0;
    virtual int setTimerIntervalValue(int timerIntervalval)=0;
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)=0;


    virtual int getDigitalOutputPin() = 0;
    virtual String& getHyd_Name()=0;
    virtual int gettimerInterval()=0;
    virtual int gettimerPeriod()=0;

};

class DGOutput1 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;
class DGOutput2 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;

class DGOutput3 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;
class DGOutput4 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;
class DGOutput5 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;

class DGOutput6 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;

class DGOutput7 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;

class DGOutput8 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;

class DGOutput9 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;

class DGOutput10 : public ActuatorsOutPut {
  private:
  int digitalOutputPin;
  String Hyd_Name;
  double timerInterval;
  double timerPeriod;
  public:
    virtual void setDigitalOutputPin(int PinNo) {
      digitalOutputPin= PinNo;
    }
    virtual void setHyd_Name(const String& HydName)
    {
        Hyd_Name = HydName;
        //Hyd_Name = "PH";
    }
    virtual int setTimerIntervalValue(int timerIntervalval)
    {
        timerInterval = timerIntervalval;
    }
    virtual int setTimerIntervalPeriod(int timerIntervalPeriod)
    {
        timerPeriod= timerIntervalPeriod;
    }

    virtual int getDigitalOutputPin()
    {
        return digitalOutputPin;
    }
    virtual int gettimerInterval()
    {
        return timerInterval;
    }
    virtual int gettimerPeriod()
    {
        return timerPeriod;
    } 
    virtual String& getHyd_Name()
    {
        return Hyd_Name;
    } 
} ;
