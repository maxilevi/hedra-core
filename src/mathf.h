/*
 * Created by Maximiliano Levi on 24/09/2019.
 */

#ifndef HEDRACORE_MATHF_H
#define HEDRACORE_MATHF_H

float trilinearInterpolation(float xm_ym_zm, float xp_ym_zm, float xm_yp_zm, float xp_yp_zm, float xm_ym_zp, float xp_ym_zp, float xm_yp_zp, float xp_yp_zp, float x, float y, float z)
{
    return (xm_ym_zm * (1 - x) * (1 - y) * (1 - z)) + (xp_ym_zm * x * (1 - y) * (1 - z)) + (xm_yp_zm * (1 - x) * y * (1 - z)) + (xp_yp_zm * x * y * (1 - z)) +
           (xm_ym_zp * (1 - x) * (1 - y) * z) + (xp_ym_zp * x * (1 - y) * z) + (xm_yp_zp * (1 - x) * y * z) + (xp_yp_zp * x * y * z);
}

int min(int a, int b) {
    return a < b ? a : b;
}

#endif //HEDRACORE_MATHF_H
