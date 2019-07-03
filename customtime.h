#ifndef CUSTOMTIME_H
#define CUSTOMTIME_H

class CustomTime
{
public:
    CustomTime();
    int getHours(){ return hours;}
    int getMinutes(){ return minutes;}
    int getSeconds(){ return seconds;}
    void setTime(int hours, int minutes);
    void setHours(int local_hours){
        hours = local_hours;
    }
    void setMinutes(int local_minutes){
        minutes = local_minutes;
    }
    void setSeconds(int local_seconds){
        seconds = local_seconds;
    }

private:
    int hours;
    int minutes;
    int seconds;
};

#endif // CUSTOMTIME_H
