#include <linux/types.h>
#include <mach/mt_pm_ldo.h>
#include <stk_cust_alsps.h>

static struct alsps_hw cust_alsps_hw = {
	.i2c_num    = 2,
	.polling_mode_ps =0,
	.polling_mode_als =1,
	.power_id   = MT65XX_POWER_NONE,    /*LDO is not used*/
	.power_vol  = VOL_DEFAULT,          /*LDO is not used*/
	.i2c_addr   = {0x90, 0x00, 0x00, 0x00},	/*STK3x1x*/
	.als_level  = {0,  10, 36, 59, 82, 132, 205, 273, 500, 845, 1136, 1545, 2364, 4655, 6982},	/* als_code */
//	.als_value  = {150, 150,  880, 880,  1280, 1280,  1280,  1280,  1280,  5000,  5000,  5000, 5000,  10240, 10240,10240  },    /*wangjie@201400922*//*modiy by stk 20141011*/	
    .als_value  = {0,0,150, 340, 430, 570,  700,  800,  950,  1500,  3000,  5000, 7000, 9000, 10240, 10240},        //wenggaojian@wind-mobi.com 20150702
	.state_val = 0x0,		/* disable all */
	.psctrl_val =0x31, //0x33,//0x31		/* ps_persistance=4, ps_gain=64X, PS_IT=0.391ms */
	.alsctrl_val = 0x3A,//0x29//modiy by stk 20141011	/* als_persistance=1, als_gain=64X, ALS_IT=50ms */
	.ledctrl_val = 0xBF,	/* 100mA IRDR, 64/64 LED duty FF */  
	.wait_val = 0x7,		/* 50 ms */
	.ps_threshold_high = 1700,//1300,   //1700
	.ps_threshold_low = 1600,   //1500
};
struct alsps_hw *get_cust_alsps_hw_stk3x1x(void) {	
    return &cust_alsps_hw;
}
