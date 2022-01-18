#include "common.h"

typedef struct {
    __REG GPIO_REVISION;  // 3h
    __RESERVED res[3];
    __REG GPIO_SYSCONFIG; // 
    __RESERVED res1[3];
    __REG GPIO_EOI;
    __REG GPIO_IRQSTATUS_RAW_0;
    __REG GPIO_IRQSTATUS_RAW_1;
    __REG GPIO_IRQSTATUS_0;
    __REG GPIO_IRQSTATUS_1;
    __REG GPIO_IRQSTATUS_SET_0;
    __REG GPIO_IRQSTATUS_SET_1;
    __REG GPIO_IRQSTATUS_CLR_0;
    __REG GPIO_IRQSTATUS_CLR_1;
    __REG GPIO_IRQWAKEN_0;
    __REG GPIO_IRQWAKEN_1;
    __RESERVED res2[50];
    __REG GPIO_SYSSTATUS;
    __RESERVED res3[6];
    __REG GPIO_CTRL;
    __REG GPIO_OE;
    __REG GPIO_DATAIN;
    __REG GPIO_DATAOUT;
    __REG GPIO_LEVELDETECT0;
    __REG GPIO_LEVELDETECT1;
    __REG GPIO_RISINGDETECT;
    __REG GPIO_FALLINGDETECT;
    __REG GPIO_DEBOUNCENABLE;
    __REG GPIO_DEBOUNCINGTIME;
    __RESERVED res4[14];
    __REG GPIO_CLEARDATAOUT;
    __REG GPIO_SETDATAOUT;
}GPIO_Typedef;


GPIO_Typedef* GPIO0 = (GPIO_Typedef*)0x44E07000;
GPIO_Typedef* GPIO1 = (GPIO_Typedef*)0x4804C000;
GPIO_Typedef* GPIO2 = (GPIO_Typedef*)0x481AC000;
GPIO_Typedef* GPIO3 = (GPIO_Typedef*)0x481AE000;