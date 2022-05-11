#include "linked_list.h"

float calc_avg(float grade1, float grade2, float grade3, bool ignore) {
    if(ignore) {
        if(grade1 == -1 && grade2 == -1 && grade3 == -1) {
            return -1;
        } else if(grade1 == -1 && grade2 == -1) {
            return grade3;
        } else if(grade2 == -1 && grade3 == -1) {
            return grade1;
        } else if(grade1 == -1 &&grade3 == -1) {
            return grade2;
        } else if(grade1 == -1) {
            return (grade2 + grade3) / 2.0;
        } else if(grade2 == -1) {
            return (grade1 + grade3) / 2.0; 
        } else if(grade3 == -1) {
            return (grade1 + grade2) / 2.0;
        } else {
            return (grade1 + grade2 + grade3) / 3.0;
        }
    } else {
        if(grade1 == -1 && grade2 == -1 && grade3 == -1) {
            return 0;
        } else if(grade1 == -1 && grade2 == -1) {
            return grade3 / 3.0;
        } else if(grade2 == -1 && grade3 == -1) {
            return grade1 / 3.0;
        } else if(grade1 == -1 &&grade3 == -1) {
            return grade2 / 3.0;
        } else if(grade1 == -1) {
            return (grade2 + grade3) / 3.0;
        } else if(grade2 == -1) {
            return (grade1 + grade3) / 3.0; 
        } else if(grade3 == -1) {
            return (grade1 + grade2) / 3.0;
        } else {
            return (grade1 + grade2 + grade3) / 3.0;
        }
    }
    
    
}
