#include "customtime.h"

CustomTime::CustomTime(): hours(0), minutes(0), seconds(0){

}



void CustomTime::setTime(int loc_hours, int loc_minutes)
{
    hours = loc_hours;
    minutes = loc_minutes;
}

