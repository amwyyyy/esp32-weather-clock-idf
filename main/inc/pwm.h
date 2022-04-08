#ifndef _pwm_h_
#define _pwm_h_

/**
 * @brief 初始化pwm
 *
 */
void pwm_init(void);
/**
 * @brief 设置pwm背光
 *
 * @param value 0~10
 */
void set_bl_pwm(uint32_t value);

#endif
