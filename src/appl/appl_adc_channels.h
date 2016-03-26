#ifndef appl_adc_channels_H
#define appl_adc_channels_H


enum E_ApplAdcChannel {
    /**
     * The user's desired voltage value set up by user's lever
     */
    APPL_ADC_CH__U_SETT,

    /**
     * The user's desired current value set up by user's lever
     */
    APPL_ADC_CH__I_SETT,

    /**
     * Actually measured voltage in range [0, +35] Volts. If the voltage
     * is negative, 0 is measured.
     */
    APPL_ADC_CH__U_ACTUAL_POS,

    /**
     * Actually measured voltage in range [-35, 0] Volts. If the voltage
     * is positive, 0 is measured.
     */
    APPL_ADC_CH__U_ACTUAL_NEG,

    /**
     * Actually measured current
     */
    APPL_ADC_CH__I_ACTUAL,

    APPL_ADC_CH_CNT
};


#endif // appl_adc_channels_H
