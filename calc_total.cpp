#include "linked_list.h"

float calc_total(float grades[12], float weights[4], bool ignore) {
    float section[4], final;
    for(int i = 0; i < 4; i++) {
        section[i] = calc_avg(grades[3*i], grades[3*i + 1], grades[3*i + 2], ignore);
    }
    for(int i = 0; i < 4; i++)
        final += section[i] * weights[i];
    return final;
}
