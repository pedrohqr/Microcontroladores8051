M:main
F:G$Timer_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$UART_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$SMBus_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$SPI_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$DAC_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$Voltage_Reference_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$Port_IO_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$Oscillator_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$Interrupts_Init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$Init_Device$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$delay_ms$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$delay_us$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$delay_160ns$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$delay_320ns$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$delay_480ns$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$le_glcd$0$0({2}DF,SC:U),C,0,0,0,0,0
F:G$esc_glcd$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$conf_Y$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$conf_pag$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$limpa_glcd$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$clear_all_glcd$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$limpa_linha_glcd$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$glcd_init$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$putchar$0$0({2}DF,SV:S),Z,0,0,0,0,0
F:G$loading_screen$0$0({2}DF,SV:S),C,0,0,0,0,0
F:G$WatchDog_Int$0$0({2}DF,SV:S),C,0,0,1,16,0
F:G$UART_Int$0$0({2}DF,SV:S),C,0,0,1,4,0
F:G$Timer2_Int$0$0({2}DF,SV:S),C,0,0,1,5,0
F:G$main$0$0({2}DF,SV:S),C,0,0,0,0,0
T:Fmain$UU32[({0}S:S$U32$0$0({4}SL:U),Z,0,0)({0}S:S$S32$0$0({4}SL:S),Z,0,0)({0}S:S$UU16$0$0({4}DA2d,STUU16:S),Z,0,0)({0}S:S$U16$0$0({4}DA2d,SI:U),Z,0,0)({0}S:S$S16$0$0({4}DA2d,SI:S),Z,0,0)({0}S:S$U8$0$0({4}DA4d,SC:U),Z,0,0)({0}S:S$S8$0$0({4}DA4d,SC:S),Z,0,0)]
T:Fmain$UU16[({0}S:S$U16$0$0({2}SI:U),Z,0,0)({0}S:S$S16$0$0({2}SI:S),Z,0,0)({0}S:S$U8$0$0({2}DA2d,SC:U),Z,0,0)({0}S:S$S8$0$0({2}DA2d,SC:S),Z,0,0)]
S:Fmain$carac_esc$0$0({2}SI:S),E,0,0
S:Fmain$pag_esc$0$0({2}SI:S),E,0,0
S:Lmain.le_glcd$byte$1$23({1}SC:U),R,0,0,[r7]
S:Lmain.esc_glcd$byte$1$24({1}SC:U),R,0,0,[r7]
S:Lmain.conf_Y$y$1$26({1}SC:U),R,0,0,[r7]
S:Lmain.conf_pag$pag$1$28({1}SC:U),R,0,0,[r7]
S:Lmain.limpa_glcd$i$1$31({2}SI:S),R,0,0,[r6,r7]
S:Lmain.limpa_glcd$j$1$31({2}SI:S),R,0,0,[r4,r5]
S:Lmain.clear_all_glcd$i$1$33({2}SI:S),R,0,0,[r6,r7]
S:Lmain.clear_all_glcd$j$1$33({2}SI:S),R,0,0,[r4,r5]
S:Lmain.limpa_linha_glcd$linha$1$35({1}SC:U),R,0,0,[r7]
S:Lmain.limpa_linha_glcd$i$1$36({2}SI:S),R,0,0,[r5,r6]
S:Lmain.putchar$c$1$38({1}SC:U),R,0,0,[r7]
S:Lmain.loading_screen$i$1$43({2}SI:S),R,0,0,[r6,r7]
S:Lmain.loading_screen$y$1$43({2}SI:S),R,0,0,[r2,r3]
S:G$byteL$0$0({1}SC:U),E,0,0
S:G$byteH$0$0({1}SC:U),E,0,0
S:G$sbufH$0$0({1}SC:U),E,0,0
S:Lmain.le_glcd$cd$1$22({1}SB0$1:U),H,0,0
S:Lmain.le_glcd$cs$1$22({1}SB0$1:U),H,0,0
S:Lmain.esc_glcd$cd$1$24({1}SB0$1:U),H,0,0
S:Lmain.esc_glcd$cs$1$24({1}SB0$1:U),H,0,0
S:Lmain.conf_Y$cs$1$26({1}SB0$1:U),H,0,0
S:Lmain.conf_pag$cs$1$28({1}SB0$1:U),H,0,0
S:Lmain.limpa_glcd$cs$1$30({1}SB0$1:U),H,0,0
S:Lmain.putchar$lado$1$39({1}SB0$1:U),H,0,0
S:G$P0$0$0({1}SC:U),I,0,0
S:G$SP$0$0({1}SC:U),I,0,0
S:G$DPL$0$0({1}SC:U),I,0,0
S:G$DPH$0$0({1}SC:U),I,0,0
S:G$SFRPAGE$0$0({1}SC:U),I,0,0
S:G$SFRNEXT$0$0({1}SC:U),I,0,0
S:G$SFRLAST$0$0({1}SC:U),I,0,0
S:G$PCON$0$0({1}SC:U),I,0,0
S:G$TCON$0$0({1}SC:U),I,0,0
S:G$CPT0CN$0$0({1}SC:U),I,0,0
S:G$CPT1CN$0$0({1}SC:U),I,0,0
S:G$CPT2CN$0$0({1}SC:U),I,0,0
S:G$TMOD$0$0({1}SC:U),I,0,0
S:G$CPT0MD$0$0({1}SC:U),I,0,0
S:G$CPT1MD$0$0({1}SC:U),I,0,0
S:G$CPT2MD$0$0({1}SC:U),I,0,0
S:G$TL0$0$0({1}SC:U),I,0,0
S:G$OSCICN$0$0({1}SC:U),I,0,0
S:G$TL1$0$0({1}SC:U),I,0,0
S:G$OSCICL$0$0({1}SC:U),I,0,0
S:G$TH0$0$0({1}SC:U),I,0,0
S:G$OSCXCN$0$0({1}SC:U),I,0,0
S:G$TH1$0$0({1}SC:U),I,0,0
S:G$CKCON$0$0({1}SC:U),I,0,0
S:G$PSCTL$0$0({1}SC:U),I,0,0
S:G$P1$0$0({1}SC:U),I,0,0
S:G$SSTA0$0$0({1}SC:U),I,0,0
S:G$SFRPGCN$0$0({1}SC:U),I,0,0
S:G$CLKSEL$0$0({1}SC:U),I,0,0
S:G$SCON0$0$0({1}SC:U),I,0,0
S:G$SCON1$0$0({1}SC:U),I,0,0
S:G$SBUF0$0$0({1}SC:U),I,0,0
S:G$SBUF1$0$0({1}SC:U),I,0,0
S:G$SPI0CFG$0$0({1}SC:U),I,0,0
S:G$SPI0DAT$0$0({1}SC:U),I,0,0
S:G$P4MDOUT$0$0({1}SC:U),I,0,0
S:G$SPI0CKR$0$0({1}SC:U),I,0,0
S:G$P5MDOUT$0$0({1}SC:U),I,0,0
S:G$P6MDOUT$0$0({1}SC:U),I,0,0
S:G$P7MDOUT$0$0({1}SC:U),I,0,0
S:G$P2$0$0({1}SC:U),I,0,0
S:G$EMI0TC$0$0({1}SC:U),I,0,0
S:G$EMI0CN$0$0({1}SC:U),I,0,0
S:G$EMI0CF$0$0({1}SC:U),I,0,0
S:G$P0MDOUT$0$0({1}SC:U),I,0,0
S:G$P1MDOUT$0$0({1}SC:U),I,0,0
S:G$P2MDOUT$0$0({1}SC:U),I,0,0
S:G$P3MDOUT$0$0({1}SC:U),I,0,0
S:G$IE$0$0({1}SC:U),I,0,0
S:G$SADDR0$0$0({1}SC:U),I,0,0
S:G$SADDR1$0$0({1}SC:U),I,0,0
S:G$P1MDIN$0$0({1}SC:U),I,0,0
S:G$P2MDIN$0$0({1}SC:U),I,0,0
S:G$P3MDIN$0$0({1}SC:U),I,0,0
S:G$P3$0$0({1}SC:U),I,0,0
S:G$FLSCL$0$0({1}SC:U),I,0,0
S:G$FLACL$0$0({1}SC:U),I,0,0
S:G$IP$0$0({1}SC:U),I,0,0
S:G$SADEN0$0$0({1}SC:U),I,0,0
S:G$AMX2CF$0$0({1}SC:U),I,0,0
S:G$AMX0PRT$0$0({1}SC:U),I,0,0
S:G$AMX0CF$0$0({1}SC:U),I,0,0
S:G$AMX0SL$0$0({1}SC:U),I,0,0
S:G$AMX2SL$0$0({1}SC:U),I,0,0
S:G$ADC0CF$0$0({1}SC:U),I,0,0
S:G$ADC2CF$0$0({1}SC:U),I,0,0
S:G$ADC0L$0$0({1}SC:U),I,0,0
S:G$ADC2$0$0({1}SC:U),I,0,0
S:G$ADC0H$0$0({1}SC:U),I,0,0
S:G$SMB0CN$0$0({1}SC:U),I,0,0
S:G$CAN0STA$0$0({1}SC:U),I,0,0
S:G$SMB0STA$0$0({1}SC:U),I,0,0
S:G$SMB0DAT$0$0({1}SC:U),I,0,0
S:G$SMB0ADR$0$0({1}SC:U),I,0,0
S:G$ADC0GTL$0$0({1}SC:U),I,0,0
S:G$ADC2GT$0$0({1}SC:U),I,0,0
S:G$ADC0GTH$0$0({1}SC:U),I,0,0
S:G$ADC0LTL$0$0({1}SC:U),I,0,0
S:G$ADC2LT$0$0({1}SC:U),I,0,0
S:G$ADC0LTH$0$0({1}SC:U),I,0,0
S:G$TMR2CN$0$0({1}SC:U),I,0,0
S:G$TMR3CN$0$0({1}SC:U),I,0,0
S:G$TMR4CN$0$0({1}SC:U),I,0,0
S:G$P4$0$0({1}SC:U),I,0,0
S:G$TMR2CF$0$0({1}SC:U),I,0,0
S:G$TMR3CF$0$0({1}SC:U),I,0,0
S:G$TMR4CF$0$0({1}SC:U),I,0,0
S:G$RCAP2L$0$0({1}SC:U),I,0,0
S:G$RCAP3L$0$0({1}SC:U),I,0,0
S:G$RCAP4L$0$0({1}SC:U),I,0,0
S:G$RCAP2H$0$0({1}SC:U),I,0,0
S:G$RCAP3H$0$0({1}SC:U),I,0,0
S:G$RCAP4H$0$0({1}SC:U),I,0,0
S:G$TMR2L$0$0({1}SC:U),I,0,0
S:G$TMR3L$0$0({1}SC:U),I,0,0
S:G$TMR4L$0$0({1}SC:U),I,0,0
S:G$TMR2H$0$0({1}SC:U),I,0,0
S:G$TMR3H$0$0({1}SC:U),I,0,0
S:G$TMR4H$0$0({1}SC:U),I,0,0
S:G$SMB0CR$0$0({1}SC:U),I,0,0
S:G$PSW$0$0({1}SC:U),I,0,0
S:G$REF0CN$0$0({1}SC:U),I,0,0
S:G$DAC0L$0$0({1}SC:U),I,0,0
S:G$DAC1L$0$0({1}SC:U),I,0,0
S:G$DAC0H$0$0({1}SC:U),I,0,0
S:G$DAC1H$0$0({1}SC:U),I,0,0
S:G$DAC0CN$0$0({1}SC:U),I,0,0
S:G$DAC1CN$0$0({1}SC:U),I,0,0
S:G$HVA0CN$0$0({1}SC:U),I,0,0
S:G$PCA0CN$0$0({1}SC:U),I,0,0
S:G$CAN0DATL$0$0({1}SC:U),I,0,0
S:G$P5$0$0({1}SC:U),I,0,0
S:G$PCA0MD$0$0({1}SC:U),I,0,0
S:G$CAN0DATH$0$0({1}SC:U),I,0,0
S:G$PCA0CPM0$0$0({1}SC:U),I,0,0
S:G$CAN0ADR$0$0({1}SC:U),I,0,0
S:G$PCA0CPM1$0$0({1}SC:U),I,0,0
S:G$CAN0TST$0$0({1}SC:U),I,0,0
S:G$PCA0CPM2$0$0({1}SC:U),I,0,0
S:G$PCA0CPM3$0$0({1}SC:U),I,0,0
S:G$PCA0CPM4$0$0({1}SC:U),I,0,0
S:G$PCA0CPM5$0$0({1}SC:U),I,0,0
S:G$ACC$0$0({1}SC:U),I,0,0
S:G$PCA0CPL5$0$0({1}SC:U),I,0,0
S:G$XBR0$0$0({1}SC:U),I,0,0
S:G$PCA0CPH5$0$0({1}SC:U),I,0,0
S:G$XBR1$0$0({1}SC:U),I,0,0
S:G$XBR2$0$0({1}SC:U),I,0,0
S:G$XBR3$0$0({1}SC:U),I,0,0
S:G$EIE1$0$0({1}SC:U),I,0,0
S:G$EIE2$0$0({1}SC:U),I,0,0
S:G$ADC0CN$0$0({1}SC:U),I,0,0
S:G$ADC2CN$0$0({1}SC:U),I,0,0
S:G$P6$0$0({1}SC:U),I,0,0
S:G$PCA0CPL2$0$0({1}SC:U),I,0,0
S:G$PCA0CPH2$0$0({1}SC:U),I,0,0
S:G$PCA0CPL3$0$0({1}SC:U),I,0,0
S:G$PCA0CPH3$0$0({1}SC:U),I,0,0
S:G$PCA0CPL4$0$0({1}SC:U),I,0,0
S:G$PCA0CPH4$0$0({1}SC:U),I,0,0
S:G$RSTSRC$0$0({1}SC:U),I,0,0
S:G$B$0$0({1}SC:U),I,0,0
S:G$EIP1$0$0({1}SC:U),I,0,0
S:G$EIP2$0$0({1}SC:U),I,0,0
S:G$SPI0CN$0$0({1}SC:U),I,0,0
S:G$CAN0CN$0$0({1}SC:U),I,0,0
S:G$P7$0$0({1}SC:U),I,0,0
S:G$PCA0L$0$0({1}SC:U),I,0,0
S:G$PCA0H$0$0({1}SC:U),I,0,0
S:G$PCA0CPL0$0$0({1}SC:U),I,0,0
S:G$PCA0CPH0$0$0({1}SC:U),I,0,0
S:G$PCA0CPL1$0$0({1}SC:U),I,0,0
S:G$PCA0CPH1$0$0({1}SC:U),I,0,0
S:G$WDTCN$0$0({1}SC:U),I,0,0
S:G$PCA0$0$0({2}SI:U),I,0,0
S:G$PCA0CP0$0$0({2}SI:U),I,0,0
S:G$PCA0CP1$0$0({2}SI:U),I,0,0
S:G$PCA0CP2$0$0({2}SI:U),I,0,0
S:G$PCA0CP3$0$0({2}SI:U),I,0,0
S:G$PCA0CP4$0$0({2}SI:U),I,0,0
S:G$PCA0CP5$0$0({2}SI:U),I,0,0
S:G$CAN0DAT$0$0({2}SI:U),I,0,0
S:G$DAC0$0$0({2}SI:U),I,0,0
S:G$DAC1$0$0({2}SI:U),I,0,0
S:G$RCAP2$0$0({2}SI:U),I,0,0
S:G$RCAP3$0$0({2}SI:U),I,0,0
S:G$RCAP4$0$0({2}SI:U),I,0,0
S:G$TMR2$0$0({2}SI:U),I,0,0
S:G$TMR3$0$0({2}SI:U),I,0,0
S:G$TMR4$0$0({2}SI:U),I,0,0
S:G$ADC0GT$0$0({2}SI:U),I,0,0
S:G$ADC0LT$0$0({2}SI:U),I,0,0
S:G$ADC0$0$0({2}SI:U),I,0,0
S:G$DP$0$0({2}SI:U),I,0,0
S:G$_XPAGE$0$0({1}SC:U),I,0,0
S:G$TF1$0$0({1}SX:U),J,0,0
S:G$TR1$0$0({1}SX:U),J,0,0
S:G$TF0$0$0({1}SX:U),J,0,0
S:G$TR0$0$0({1}SX:U),J,0,0
S:G$IE1$0$0({1}SX:U),J,0,0
S:G$IT1$0$0({1}SX:U),J,0,0
S:G$IE0$0$0({1}SX:U),J,0,0
S:G$IT0$0$0({1}SX:U),J,0,0
S:G$CP0EN$0$0({1}SX:U),J,0,0
S:G$CP0OUT$0$0({1}SX:U),J,0,0
S:G$CP0RIF$0$0({1}SX:U),J,0,0
S:G$CP0FIF$0$0({1}SX:U),J,0,0
S:G$CP0HYP1$0$0({1}SX:U),J,0,0
S:G$CP0HYP0$0$0({1}SX:U),J,0,0
S:G$CP0HYN1$0$0({1}SX:U),J,0,0
S:G$CP0HYN0$0$0({1}SX:U),J,0,0
S:G$CP1EN$0$0({1}SX:U),J,0,0
S:G$CP1OUT$0$0({1}SX:U),J,0,0
S:G$CP1RIF$0$0({1}SX:U),J,0,0
S:G$CP1FIF$0$0({1}SX:U),J,0,0
S:G$CP1HYP1$0$0({1}SX:U),J,0,0
S:G$CP1HYP0$0$0({1}SX:U),J,0,0
S:G$CP1HYN1$0$0({1}SX:U),J,0,0
S:G$CP1HYN0$0$0({1}SX:U),J,0,0
S:G$CP2EN$0$0({1}SX:U),J,0,0
S:G$CP2OUT$0$0({1}SX:U),J,0,0
S:G$CP2RIF$0$0({1}SX:U),J,0,0
S:G$CP2FIF$0$0({1}SX:U),J,0,0
S:G$CP2HYP1$0$0({1}SX:U),J,0,0
S:G$CP2HYP0$0$0({1}SX:U),J,0,0
S:G$CP2HYN1$0$0({1}SX:U),J,0,0
S:G$CP2HYN0$0$0({1}SX:U),J,0,0
S:G$SM00$0$0({1}SX:U),J,0,0
S:G$SM10$0$0({1}SX:U),J,0,0
S:G$SM20$0$0({1}SX:U),J,0,0
S:G$REN0$0$0({1}SX:U),J,0,0
S:G$TB80$0$0({1}SX:U),J,0,0
S:G$RB80$0$0({1}SX:U),J,0,0
S:G$TI0$0$0({1}SX:U),J,0,0
S:G$RI0$0$0({1}SX:U),J,0,0
S:G$S1MODE$0$0({1}SX:U),J,0,0
S:G$MCE1$0$0({1}SX:U),J,0,0
S:G$REN1$0$0({1}SX:U),J,0,0
S:G$TB81$0$0({1}SX:U),J,0,0
S:G$RB81$0$0({1}SX:U),J,0,0
S:G$TI1$0$0({1}SX:U),J,0,0
S:G$RI1$0$0({1}SX:U),J,0,0
S:G$EA$0$0({1}SX:U),J,0,0
S:G$ET2$0$0({1}SX:U),J,0,0
S:G$ES0$0$0({1}SX:U),J,0,0
S:G$ET1$0$0({1}SX:U),J,0,0
S:G$EX1$0$0({1}SX:U),J,0,0
S:G$ET0$0$0({1}SX:U),J,0,0
S:G$EX0$0$0({1}SX:U),J,0,0
S:G$PT2$0$0({1}SX:U),J,0,0
S:G$PS0$0$0({1}SX:U),J,0,0
S:G$PT1$0$0({1}SX:U),J,0,0
S:G$PX1$0$0({1}SX:U),J,0,0
S:G$PT0$0$0({1}SX:U),J,0,0
S:G$PX0$0$0({1}SX:U),J,0,0
S:G$BUSY$0$0({1}SX:U),J,0,0
S:G$ENSMB$0$0({1}SX:U),J,0,0
S:G$STA$0$0({1}SX:U),J,0,0
S:G$STO$0$0({1}SX:U),J,0,0
S:G$SI$0$0({1}SX:U),J,0,0
S:G$AA$0$0({1}SX:U),J,0,0
S:G$SMBFTE$0$0({1}SX:U),J,0,0
S:G$SMBTOE$0$0({1}SX:U),J,0,0
S:G$BOFF$0$0({1}SX:U),J,0,0
S:G$EWARN$0$0({1}SX:U),J,0,0
S:G$EPASS$0$0({1}SX:U),J,0,0
S:G$RXOK$0$0({1}SX:U),J,0,0
S:G$TXOK$0$0({1}SX:U),J,0,0
S:G$LEC2$0$0({1}SX:U),J,0,0
S:G$LEC1$0$0({1}SX:U),J,0,0
S:G$LEC0$0$0({1}SX:U),J,0,0
S:G$TF2$0$0({1}SX:U),J,0,0
S:G$EXF2$0$0({1}SX:U),J,0,0
S:G$EXEN2$0$0({1}SX:U),J,0,0
S:G$TR2$0$0({1}SX:U),J,0,0
S:G$CT2$0$0({1}SX:U),J,0,0
S:G$CPRL2$0$0({1}SX:U),J,0,0
S:G$TF3$0$0({1}SX:U),J,0,0
S:G$EXF3$0$0({1}SX:U),J,0,0
S:G$EXEN3$0$0({1}SX:U),J,0,0
S:G$TR3$0$0({1}SX:U),J,0,0
S:G$CT3$0$0({1}SX:U),J,0,0
S:G$CPRL3$0$0({1}SX:U),J,0,0
S:G$TF4$0$0({1}SX:U),J,0,0
S:G$EXF4$0$0({1}SX:U),J,0,0
S:G$EXEN4$0$0({1}SX:U),J,0,0
S:G$TR4$0$0({1}SX:U),J,0,0
S:G$CT4$0$0({1}SX:U),J,0,0
S:G$CPRL4$0$0({1}SX:U),J,0,0
S:G$CY$0$0({1}SX:U),J,0,0
S:G$AC$0$0({1}SX:U),J,0,0
S:G$F0$0$0({1}SX:U),J,0,0
S:G$RS1$0$0({1}SX:U),J,0,0
S:G$RS0$0$0({1}SX:U),J,0,0
S:G$OV$0$0({1}SX:U),J,0,0
S:G$F1$0$0({1}SX:U),J,0,0
S:G$P$0$0({1}SX:U),J,0,0
S:G$CF$0$0({1}SX:U),J,0,0
S:G$CR$0$0({1}SX:U),J,0,0
S:G$CCF5$0$0({1}SX:U),J,0,0
S:G$CCF4$0$0({1}SX:U),J,0,0
S:G$CCF3$0$0({1}SX:U),J,0,0
S:G$CCF2$0$0({1}SX:U),J,0,0
S:G$CCF1$0$0({1}SX:U),J,0,0
S:G$CCF0$0$0({1}SX:U),J,0,0
S:G$AD0EN$0$0({1}SX:U),J,0,0
S:G$AD0TM$0$0({1}SX:U),J,0,0
S:G$AD0INT$0$0({1}SX:U),J,0,0
S:G$AD0BUSY$0$0({1}SX:U),J,0,0
S:G$AD0CM1$0$0({1}SX:U),J,0,0
S:G$AD0CM0$0$0({1}SX:U),J,0,0
S:G$AD0WINT$0$0({1}SX:U),J,0,0
S:G$AD0LJST$0$0({1}SX:U),J,0,0
S:G$AD2EN$0$0({1}SX:U),J,0,0
S:G$AD2TM$0$0({1}SX:U),J,0,0
S:G$AD2INT$0$0({1}SX:U),J,0,0
S:G$AD2BUSY$0$0({1}SX:U),J,0,0
S:G$AD2CM2$0$0({1}SX:U),J,0,0
S:G$AD2CM1$0$0({1}SX:U),J,0,0
S:G$AD2CM0$0$0({1}SX:U),J,0,0
S:G$AD2WINT$0$0({1}SX:U),J,0,0
S:G$SPIF$0$0({1}SX:U),J,0,0
S:G$WCOL$0$0({1}SX:U),J,0,0
S:G$MODF$0$0({1}SX:U),J,0,0
S:G$RXOVRN$0$0({1}SX:U),J,0,0
S:G$NSSMD1$0$0({1}SX:U),J,0,0
S:G$NSSMD0$0$0({1}SX:U),J,0,0
S:G$TXBMT$0$0({1}SX:U),J,0,0
S:G$SPIEN$0$0({1}SX:U),J,0,0
S:G$CANINIT$0$0({1}SX:U),J,0,0
S:G$CANIE$0$0({1}SX:U),J,0,0
S:G$CANSIE$0$0({1}SX:U),J,0,0
S:G$CANEIE$0$0({1}SX:U),J,0,0
S:G$CANIF$0$0({1}SX:U),J,0,0
S:G$CANDAR$0$0({1}SX:U),J,0,0
S:G$CANCCE$0$0({1}SX:U),J,0,0
S:G$CANTEST$0$0({1}SX:U),J,0,0
S:G$P0_0$0$0({1}SX:U),J,0,0
S:G$P0_1$0$0({1}SX:U),J,0,0
S:G$P0_2$0$0({1}SX:U),J,0,0
S:G$P0_3$0$0({1}SX:U),J,0,0
S:G$P0_4$0$0({1}SX:U),J,0,0
S:G$P0_5$0$0({1}SX:U),J,0,0
S:G$P0_6$0$0({1}SX:U),J,0,0
S:G$P0_7$0$0({1}SX:U),J,0,0
S:G$P1_0$0$0({1}SX:U),J,0,0
S:G$P1_1$0$0({1}SX:U),J,0,0
S:G$P1_2$0$0({1}SX:U),J,0,0
S:G$P1_3$0$0({1}SX:U),J,0,0
S:G$P1_4$0$0({1}SX:U),J,0,0
S:G$P1_5$0$0({1}SX:U),J,0,0
S:G$P1_6$0$0({1}SX:U),J,0,0
S:G$P1_7$0$0({1}SX:U),J,0,0
S:G$P2_0$0$0({1}SX:U),J,0,0
S:G$P2_1$0$0({1}SX:U),J,0,0
S:G$P2_2$0$0({1}SX:U),J,0,0
S:G$P2_3$0$0({1}SX:U),J,0,0
S:G$P2_4$0$0({1}SX:U),J,0,0
S:G$P2_5$0$0({1}SX:U),J,0,0
S:G$P2_6$0$0({1}SX:U),J,0,0
S:G$P2_7$0$0({1}SX:U),J,0,0
S:G$P3_0$0$0({1}SX:U),J,0,0
S:G$P3_1$0$0({1}SX:U),J,0,0
S:G$P3_2$0$0({1}SX:U),J,0,0
S:G$P3_3$0$0({1}SX:U),J,0,0
S:G$P3_4$0$0({1}SX:U),J,0,0
S:G$P3_5$0$0({1}SX:U),J,0,0
S:G$P3_6$0$0({1}SX:U),J,0,0
S:G$P3_7$0$0({1}SX:U),J,0,0
S:G$P4_0$0$0({1}SX:U),J,0,0
S:G$P4_1$0$0({1}SX:U),J,0,0
S:G$P4_2$0$0({1}SX:U),J,0,0
S:G$P4_3$0$0({1}SX:U),J,0,0
S:G$P4_4$0$0({1}SX:U),J,0,0
S:G$P4_5$0$0({1}SX:U),J,0,0
S:G$P4_6$0$0({1}SX:U),J,0,0
S:G$P4_7$0$0({1}SX:U),J,0,0
S:G$P5_0$0$0({1}SX:U),J,0,0
S:G$P5_1$0$0({1}SX:U),J,0,0
S:G$P5_2$0$0({1}SX:U),J,0,0
S:G$P5_3$0$0({1}SX:U),J,0,0
S:G$P5_4$0$0({1}SX:U),J,0,0
S:G$P5_5$0$0({1}SX:U),J,0,0
S:G$P5_6$0$0({1}SX:U),J,0,0
S:G$P5_7$0$0({1}SX:U),J,0,0
S:G$P6_0$0$0({1}SX:U),J,0,0
S:G$P6_1$0$0({1}SX:U),J,0,0
S:G$P6_2$0$0({1}SX:U),J,0,0
S:G$P6_3$0$0({1}SX:U),J,0,0
S:G$P6_4$0$0({1}SX:U),J,0,0
S:G$P6_5$0$0({1}SX:U),J,0,0
S:G$P6_6$0$0({1}SX:U),J,0,0
S:G$P6_7$0$0({1}SX:U),J,0,0
S:G$P7_0$0$0({1}SX:U),J,0,0
S:G$P7_1$0$0({1}SX:U),J,0,0
S:G$P7_2$0$0({1}SX:U),J,0,0
S:G$P7_3$0$0({1}SX:U),J,0,0
S:G$P7_4$0$0({1}SX:U),J,0,0
S:G$P7_5$0$0({1}SX:U),J,0,0
S:G$P7_6$0$0({1}SX:U),J,0,0
S:G$P7_7$0$0({1}SX:U),J,0,0
S:G$Timer_Init$0$0({2}DF,SV:S),C,0,0
S:G$UART_Init$0$0({2}DF,SV:S),C,0,0
S:G$SMBus_Init$0$0({2}DF,SV:S),C,0,0
S:G$SPI_Init$0$0({2}DF,SV:S),C,0,0
S:G$DAC_Init$0$0({2}DF,SV:S),C,0,0
S:G$Voltage_Reference_Init$0$0({2}DF,SV:S),C,0,0
S:G$Port_IO_Init$0$0({2}DF,SV:S),C,0,0
S:G$Oscillator_Init$0$0({2}DF,SV:S),C,0,0
S:G$Interrupts_Init$0$0({2}DF,SV:S),C,0,0
S:G$Init_Device$0$0({2}DF,SV:S),C,0,0
S:G$delay_ms$0$0({2}DF,SV:S),C,0,0
S:G$delay_us$0$0({2}DF,SV:S),C,0,0
S:G$delay_160ns$0$0({2}DF,SV:S),C,0,0
S:G$delay_320ns$0$0({2}DF,SV:S),C,0,0
S:G$delay_480ns$0$0({2}DF,SV:S),C,0,0
S:G$le_glcd$0$0({2}DF,SC:U),C,0,0
S:G$esc_glcd$0$0({2}DF,SV:S),C,0,0
S:G$conf_Y$0$0({2}DF,SV:S),C,0,0
S:G$conf_pag$0$0({2}DF,SV:S),C,0,0
S:G$limpa_glcd$0$0({2}DF,SV:S),C,0,0
S:G$clear_all_glcd$0$0({2}DF,SV:S),C,0,0
S:G$limpa_linha_glcd$0$0({2}DF,SV:S),C,0,0
S:G$glcd_init$0$0({2}DF,SV:S),C,0,0
S:G$loading_screen$0$0({2}DF,SV:S),C,0,0
S:G$WatchDog_Int$0$0({2}DF,SV:S),C,0,0
S:G$_print_format$0$0({2}DF,SI:S),C,0,0
S:G$printf_small$0$0({2}DF,SV:S),C,0,0
S:G$printf$0$0({2}DF,SI:S),C,0,0
S:G$vprintf$0$0({2}DF,SI:S),C,0,0
S:G$sprintf$0$0({2}DF,SI:S),C,0,0
S:G$vsprintf$0$0({2}DF,SI:S),C,0,0
S:G$puts$0$0({2}DF,SI:S),C,0,0
S:G$getchar$0$0({2}DF,SC:U),C,0,0
S:G$putchar$0$0({2}DF,SV:S),C,0,0
S:G$printf_fast$0$0({2}DF,SV:S),C,0,0
S:G$printf_fast_f$0$0({2}DF,SV:S),C,0,0
S:G$printf_tiny$0$0({2}DF,SV:S),C,0,0
S:G$UART_Int$0$0({2}DF,SV:S),C,0,0
S:G$Timer2_Int$0$0({2}DF,SV:S),C,0,0
S:G$main$0$0({2}DF,SV:S),C,0,0
S:G$samples$0$0({1024}DA1024d,SC:U),D,0,0
S:G$fonte$0$0({480}DA96d,DA5d,SC:U),D,0,0
S:Fmain$__str_0$0$0({11}DA11d,SC:S),D,0,0
S:Fmain$__str_1$0$0({15}DA15d,SC:S),D,0,0
S:Fmain$__str_2$0$0({15}DA15d,SC:S),D,0,0
S:Fmain$__str_3$0$0({15}DA15d,SC:S),D,0,0
S:Fmain$__str_4$0$0({14}DA14d,SC:S),D,0,0
