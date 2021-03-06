EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:176122-6
LIBS:art-electro-conn
LIBS:art-electro-conn_2
LIBS:art-electro-ic
LIBS:art-electro-max
LIBS:art-electro-power
LIBS:LMV324IDR
LIBS:logo
LIBS:logo_flipped
LIBS:MAX9926-9927
LIBS:max9939
LIBS:max31855
LIBS:stm32
LIBS:tc4427
LIBS:lm2596
LIBS:mos_p_numbered-pins
LIBS:rn-41
LIBS:skqucaa010_joystick
LIBS:itead_hc-0X_bluetooth
LIBS:frankenso-cache
EELAYER 27 0
EELAYER END
$Descr A 11000 8500
encoding utf-8
Sheet 9 14
Title "Frankenso"
Date "3 nov 2014"
Rev ".02"
Comp "rusEFI.com"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_1 P1002
U 1 1 519D13C2
P 7750 6700
F 0 "P1002" H 7830 6700 40  0000 L CNN
F 1 "CONN_1" H 7750 6755 30  0001 C CNN
F 2 "SIL-1" V 1130 2600 60  0001 C CNN
F 3 "" H 7750 6700 60  0001 C CNN
F 4 "DO NOT POPULATE,DNP" V 1130 2600 60  0001 C CNN "mfg,mfg#"
F 5 "DO NOT POPULATE,DNP" V 1130 2600 60  0001 C CNN "vend1,vend1#"
	1    7750 6700
	-1   0    0    1   
$EndComp
$Comp
L CP1 C1001
U 1 1 51297942
P 6800 6600
F 0 "C1001" V 6650 6350 50  0000 L CNN
F 1 "470uF 25V" V 7000 6350 50  0000 L CNN
F 2 "SMDSVP10" H 6800 6600 60  0001 C CNN
F 3 "" H 6800 6600 60  0001 C CNN
F 4 "Nichicon,UBC1V101MNS1GS" H 6800 6600 60  0001 C CNN "MFG,MFG#"
F 5 "digi,493-4471-1-ND" H 6800 6600 60  0001 C CNN "VEND1,VEND1#"
	1    6800 6600
	-1   0    0    -1  
$EndComp
$Comp
L R R1002
U 1 1 512925E9
P 8650 6600
F 0 "R1002" V 8730 6600 50  0000 C CNN
F 1 "1k" V 8650 6600 50  0000 C CNN
F 2 "SM0805" V 1130 2600 60  0001 C CNN
F 3 "" H 8650 6600 60  0001 C CNN
F 4 "VISHAY,CRCW0805100KFKEA" V 1130 2600 60  0001 C CNN "mfg,mfg#"
F 5 "DIGI,CRCW0805100KFKEA" V 1130 2600 60  0001 C CNN "vend1,vend1#"
	1    8650 6600
	0    1    1    0   
$EndComp
$Comp
L LED D1005
U 1 1 5129222C
P 8600 6750
F 0 "D1005" H 8600 6600 50  0000 C CNN
F 1 "LED-grn" H 8600 6925 50  0001 C CNN
F 2 "LED-0805" H 8600 6750 60  0001 C CNN
F 3 "" H 8600 6750 60  0001 C CNN
F 4 "lite-on,LTST-C171GKT" H 8600 6750 60  0001 C CNN "mfg,mfg#"
F 5 "digi,160-1423-1-ND" H 8600 6750 60  0001 C CNN "VEND1,VEND1#"
	1    8600 6750
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR L1001
U 1 1 512921EB
P 8600 6450
F 0 "L1001" V 8550 6450 40  0000 C CNN
F 1 "38uH" V 8700 6450 40  0000 C CNN
F 2 "SM100uH" H 8600 6450 60  0001 C CNN
F 3 "" H 8600 6450 60  0001 C CNN
F 4 "ref_PULSE,PE-54040-S" V 8600 6450 60  0001 C CNN "MFG,MFG#"
F 5 "sky-macau.com,3817361683" V 8600 6450 60  0001 C CNN "VEND1,VEND1#"
	1    8600 6450
	0    -1   -1   0   
$EndComp
$Comp
L LM2596 U1001
U 1 1 52C4CA58
P 7450 6550
F 0 "U1001" H 7600 6850 60  0000 C CNN
F 1 "LM2596" H 7200 6400 60  0000 C CNN
F 2 "DPAK5" H 7450 6550 60  0001 C CNN
F 3 "~" H 7450 6550 60  0000 C CNN
F 4 "linear,2596-5.0" H 7450 6550 60  0001 C CNN "mfg,mfg#"
F 5 "digi,LM2596S-5.0/NOPB-ND" H 7450 6550 60  0001 C CNN "vend1,vend1#"
F 6 "sky-macau.com,6841999795" H 7450 6550 60  0001 C CNN "vend2,vend2#"
	1    7450 6550
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR L1002
U 1 1 52C4CD12
P 9350 6450
F 0 "L1002" V 9300 6400 40  0000 C CNN
F 1 "38uH" V 9450 6450 40  0000 C CNN
F 2 "SM100uH" H 9350 6450 60  0001 C CNN
F 3 "" H 9350 6450 60  0001 C CNN
F 4 "ref_PULSE,PE-54040-S" V 9350 6450 60  0001 C CNN "MFG,MFG#"
F 5 "sky-macau.com,3817361683" V 9350 6450 60  0001 C CNN "VEND1,VEND1#"
	1    9350 6450
	0    -1   -1   0   
$EndComp
$Comp
L SCHDPAK D1004
U 1 1 52C4CE0F
P 8300 6650
F 0 "D1004" H 8300 6750 40  0000 C CNN
F 1 "SCHDPAK" H 8300 6550 40  0001 C CNN
F 2 "DPAK2" H 8300 6650 60  0001 C CNN
F 3 "~" H 8300 6650 60  0000 C CNN
F 4 "VISHAY,VS-50WQ04FNPBF" H 8300 6650 60  0001 C CNN "MFG,MFG#"
F 5 "DIGI,VS-50WQ04FNPBF-ND" H 8300 6650 60  0001 C CNN "VEND1,VEND1#"
F 6 "DO NOT POPULATE" H 8300 6650 60  0001 C CNN "Field6"
	1    8300 6650
	0    -1   -1   0   
$EndComp
Connection ~ -4675 3450
Connection ~ 9050 6850
Connection ~ 7450 6850
Wire Wire Line
	6800 6800 6800 6850
Connection ~ 6800 6850
Wire Wire Line
	8800 6750 8800 6850
Connection ~ 8800 6850
Wire Wire Line
	8400 6750 8400 6600
Wire Wire Line
	8900 6300 8900 6600
Wire Wire Line
	8900 6450 9050 6450
Connection ~ 9050 6450
Wire Wire Line
	5150 6400 7000 6400
Connection ~ 6800 6400
Wire Wire Line
	7000 6550 7000 6850
Connection ~ 7000 6850
Wire Wire Line
	8900 6300 7900 6300
Wire Wire Line
	7900 6300 7900 6400
Connection ~ 8900 6450
Wire Wire Line
	10000 6850 10000 6650
Connection ~ 9650 6850
Wire Wire Line
	10000 6450 9650 6450
Wire Wire Line
	7900 6450 7900 6700
Wire Wire Line
	7900 6450 8300 6450
Connection ~ 7900 6550
Connection ~ 8300 6450
Connection ~ 8250 6850
Connection ~ 8350 6850
Connection ~ 9650 6450
Text Label 6800 6400 0    60   ~ 0
VBAT
Text Label 8200 6300 0    60   ~ 0
FB
Text Label 8200 6450 0    60   ~ 0
OUT
$Comp
L GND #PWR0102
U 1 1 52C4D1EB
P 7450 6900
F 0 "#PWR0102" H 7450 6900 30  0001 C CNN
F 1 "GND" H 7450 6830 30  0001 C CNN
F 2 "" H 7450 6900 60  0000 C CNN
F 3 "" H 7450 6900 60  0000 C CNN
	1    7450 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 6850 7450 6900
$Comp
L DIODE D1002
U 1 1 52C61746
P 6100 6600
F 0 "D1002" H 6100 6700 40  0000 C CNN
F 1 "TVS" H 6100 6500 40  0000 C CNN
F 2 "D3" H 6100 6600 60  0001 C CNN
F 3 "~" H 6100 6600 60  0000 C CNN
F 4 "fairchild,BZX79C20" H 6100 6600 60  0001 C CNN "mfg,mfg#"
F 5 "digi,BZX79C20-ND" H 6100 6600 60  0001 C CNN "vend1,vend1"
F 6 "sky-macau.com,8262743708" H 6100 6600 60  0001 C CNN "vend2,vend2#"
	1    6100 6600
	0    -1   -1   0   
$EndComp
$Comp
L MOS_PRO Q1001
U 1 1 52C6272D
P 4950 6500
F 0 "Q1001" H 4950 6690 60  0000 R CNN
F 1 "MOS_PRO" H 4950 6320 60  0001 R CNN
F 2 "SOT23" H 4950 6500 60  0001 C CNN
F 3 "~" H 4950 6500 60  0000 C CNN
F 4 "vishay,SI2323DS-T1-E3" H 4950 6500 60  0001 C CNN "mfg,mfg"
F 5 "digi,SI2323DS-T1-E3CT-ND" H 4950 6500 60  0001 C CNN "vend1,vend1"
F 6 "sky-macau.com,4824167646" H 4950 6500 60  0001 C CNN "vend2,vend2#"
	1    4950 6500
	0    -1   -1   0   
$EndComp
Connection ~ 6350 6400
Connection ~ 6100 6400
Wire Wire Line
	6350 6800 6350 6850
Wire Wire Line
	6100 6800 6100 6850
Connection ~ 6350 6850
Wire Wire Line
	4050 6850 4050 6600
Connection ~ 6100 6850
$Comp
L R R1001
U 1 1 533A08F3
P 5500 6700
F 0 "R1001" V 5580 6700 50  0000 C CNN
F 1 "1k" V 5500 6700 50  0000 C CNN
F 2 "SM0805" V 1130 2600 60  0001 C CNN
F 3 "" H 5500 6700 60  0001 C CNN
F 4 "VISHAY,CRCW0805100KFKEA" V 1130 2600 60  0001 C CNN "mfg,mfg#"
F 5 "DIGI,CRCW0805100KFKEA" V 1130 2600 60  0001 C CNN "vend1,vend1#"
	1    5500 6700
	0    -1   -1   0   
$EndComp
$Comp
L ZENERSMALL D1001
U 1 1 533A08FB
P 5250 6600
F 0 "D1001" H 5350 6500 40  0000 C CNN
F 1 "ZENERSMALL" H 5250 6500 30  0001 C CNN
F 2 "SM1206" H 5250 6600 60  0001 C CNN
F 3 "~" H 5250 6600 60  0000 C CNN
F 4 "onsemi,MM3Z6V8T1G" H 5250 6600 60  0001 C CNN "mfg,mfg#"
F 5 "digi,MM3Z6V8T1GOSCT-ND" H 5250 6600 60  0001 C CNN "vend1,vend1#"
F 6 "sky-macau.com,5633100308" H 5250 6600 60  0001 C CNN "vend2,vend2#"
	1    5250 6600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 6700 5750 6850
Connection ~ 5750 6850
Wire Wire Line
	5250 6700 4950 6700
$Comp
L FUSE F1001
U 1 1 533A8E21
P 4400 6400
F 0 "F1001" H 4500 6450 40  0000 C CNN
F 1 "3.5A" H 4300 6350 40  0000 C CNN
F 2 "SIL-2" H 4400 6400 60  0001 C CNN
F 3 "~" H 4400 6400 60  0000 C CNN
F 4 "0R,jumperwire" H 4400 6400 60  0001 C CNN "mfg,mfg#"
F 5 "0R,jumperwire" H 4400 6400 60  0001 C CNN "vend1,vend1#"
	1    4400 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 6400 4150 6400
Wire Wire Line
	4650 6400 4750 6400
Wire Wire Line
	5250 6500 5250 6400
Connection ~ 5250 6400
$Comp
L DIODESCH D1006
U 1 1 533B6631
P 8100 6650
F 0 "D1006" H 8100 6750 40  0000 C CNN
F 1 "DIODESCH" H 8100 6550 40  0001 C CNN
F 2 "D4" H 8100 6650 60  0001 C CNN
F 3 "~" H 8100 6650 60  0000 C CNN
F 4 "do no populate,DNP" H 8100 6650 60  0001 C CNN "mfg,mfg#"
F 5 "sky-macau.com,1438219496" H 8100 6650 60  0001 C CNN "VEND1,VEND1#"
	1    8100 6650
	0    -1   -1   0   
$EndComp
Connection ~ 8100 6450
Connection ~ 8100 6850
Wire Notes Line
	8100 6900 8100 7050
Text Notes 7700 7150 0    60   ~ 0
ALT DIODE FOR CHINA ASSEMBLER\nLIMITS OUTPUT TO 2.3A
Text Label 4650 6400 0    60   ~ 0
Vf
Wire Wire Line
	4050 6850 10000 6850
$Comp
L CP1 C1002
U 1 1 5378A039
P 9050 6650
F 0 "C1002" V 8900 6550 50  0000 L CNN
F 1 "220uF 16V" H 8600 6500 50  0000 L CNN
F 2 "SM2512" H 9050 6650 60  0001 C CNN
F 3 "" H 9050 6650 60  0001 C CNN
F 4 "kemet,T491D227K016AT" H 9050 6650 60  0001 C CNN "MFG,MFG#"
F 5 "digi,399-10429-1-ND" H 9050 6650 60  0001 C CNN "VEND1,VEND1#"
F 6 "sky-macau.com,8702041755" H 9050 6650 60  0001 C CNN "vend2,vend2#"
	1    9050 6650
	-1   0    0    -1  
$EndComp
Text HLabel 4050 6400 0    60   Input ~ 0
Vin
Text HLabel 4050 6600 0    60   Input ~ 0
GND
Text HLabel 9650 6450 1    60   Input ~ 0
5V-REG
$Comp
L CP1 C1003
U 1 1 53D50AD9
P 9650 6650
F 0 "C1003" V 9500 6550 50  0000 L CNN
F 1 "220uF 16V" H 9200 6500 50  0000 L CNN
F 2 "SM2512" H 9650 6650 60  0001 C CNN
F 3 "" H 9650 6650 60  0001 C CNN
F 4 "kemet,T491D227K016AT" H 9650 6650 60  0001 C CNN "MFG,MFG#"
F 5 "digi,399-10429-1-ND" H 9650 6650 60  0001 C CNN "VEND1,VEND1#"
F 6 "sky-macau.com,8702041755" H 9650 6650 60  0001 C CNN "vend2,vend2#"
	1    9650 6650
	-1   0    0    -1  
$EndComp
$Comp
L DIODE D1003
U 1 1 53D51276
P 6350 6600
F 0 "D1003" H 6350 6700 40  0000 C CNN
F 1 "TVS" H 6350 6500 40  0000 C CNN
F 2 "D3" H 6350 6600 60  0001 C CNN
F 3 "~" H 6350 6600 60  0000 C CNN
F 4 "fairchild,BZX79C20" H 6350 6600 60  0001 C CNN "mfg,mfg#"
F 5 "digi,BZX79C20-ND" H 6350 6600 60  0001 C CNN "vend1,vend1"
F 6 "sky-macau.com,8262743708" H 6350 6600 60  0001 C CNN "vend2,vend2#"
	1    6350 6600
	0    -1   -1   0   
$EndComp
$Comp
L CONN_1 P901
U 1 1 53DF5B0B
P 4000 6250
F 0 "P901" H 4080 6250 40  0000 L CNN
F 1 "CONN_1" H 4000 6305 30  0001 C CNN
F 2 "SIL-1" H 4000 6250 60  0001 C CNN
F 3 "" H 4000 6250 60  0000 C CNN
	1    4000 6250
	-1   0    0    1   
$EndComp
$Comp
L CONN_1 P902
U 1 1 53DF5B1A
P 5250 6250
F 0 "P902" H 5330 6250 40  0000 L CNN
F 1 "CONN_1" H 5250 6305 30  0001 C CNN
F 2 "SIL-1" H 5250 6250 60  0001 C CNN
F 3 "" H 5250 6250 60  0000 C CNN
	1    5250 6250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4150 6400 4150 6250
$EndSCHEMATC
