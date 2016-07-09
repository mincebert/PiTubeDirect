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
LIBS:pitubedirect-hat-dip-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74LS245 U2
U 1 1 5742C432
P 6100 4400
F 0 "U2" H 6200 4975 50  0000 L BNN
F 1 "74LVC245AN" H 6150 3825 50  0000 L TNN
F 2 "Housings_DIP:DIP-20_W7.62mm" H 6100 4400 50  0001 C CNN
F 3 "" H 6100 4400 50  0000 C CNN
	1    6100 4400
	-1   0    0    1   
$EndComp
$Comp
L CONN_02X20 P1
U 1 1 5742C4D6
P 3050 4650
F 0 "P1" H 3050 5700 50  0000 C CNN
F 1 "CONN_02X20" V 3050 4650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x20" H 3050 3700 50  0001 C CNN
F 3 "" H 3050 3700 50  0000 C CNN
	1    3050 4650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5742CD35
P 2300 3850
F 0 "#PWR01" H 2300 3600 50  0001 C CNN
F 1 "GND" H 2300 3700 50  0000 C CNN
F 2 "" H 2300 3850 50  0000 C CNN
F 3 "" H 2300 3850 50  0000 C CNN
	1    2300 3850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 5742CE14
P 2300 5400
F 0 "#PWR02" H 2300 5250 50  0001 C CNN
F 1 "+5V" H 2300 5540 50  0000 C CNN
F 2 "" H 2300 5400 50  0000 C CNN
F 3 "" H 2300 5400 50  0000 C CNN
	1    2300 5400
	1    0    0    -1  
$EndComp
Text Label 5300 4200 0    60   ~ 0
TD0
Text Label 5300 4300 0    60   ~ 0
TD1
Text Label 5300 4400 0    60   ~ 0
TD2
Text Label 5300 4500 0    60   ~ 0
TD3
Text Label 5300 4600 0    60   ~ 0
TD4
Text Label 5300 4700 0    60   ~ 0
TD5
Text Label 5300 4800 0    60   ~ 0
TD6
Text Label 5300 4900 0    60   ~ 0
TD7
Text Label 5250 2900 0    60   ~ 0
TA0
Text Label 5250 3000 0    60   ~ 0
TA1
Text Label 5250 3100 0    60   ~ 0
TA2
Text Label 5150 2500 0    60   ~ 0
TRnW
Text Label 5150 2600 0    60   ~ 0
TPHI2
Text Label 5100 2700 0    60   ~ 0
TnTUBE
Text Label 5150 2800 0    60   ~ 0
tnRST
NoConn ~ 3300 3900
NoConn ~ 3300 5400
NoConn ~ 3300 5500
NoConn ~ 3300 5600
$Comp
L GND #PWR03
U 1 1 5742EF3B
P 6950 2050
F 0 "#PWR03" H 6950 1800 50  0001 C CNN
F 1 "GND" H 6950 1900 50  0000 C CNN
F 2 "" H 6950 2050 50  0000 C CNN
F 3 "" H 6950 2050 50  0000 C CNN
	1    6950 2050
	-1   0    0    1   
$EndComp
$Comp
L C_Small C1
U 1 1 5742F6BB
P 2700 2100
F 0 "C1" H 2710 2170 50  0000 L CNN
F 1 "100n" H 2710 2020 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2_P5" H 2700 2100 50  0001 C CNN
F 3 "" H 2700 2100 50  0000 C CNN
	1    2700 2100
	1    0    0    -1  
$EndComp
$Comp
L C_Small C2
U 1 1 5742F75A
P 3050 2100
F 0 "C2" H 3060 2170 50  0000 L CNN
F 1 "100n" H 3060 2020 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2_P5" H 3050 2100 50  0001 C CNN
F 3 "" H 3050 2100 50  0000 C CNN
	1    3050 2100
	1    0    0    -1  
$EndComp
$Comp
L CP1_Small C3
U 1 1 5742F7C7
P 3400 2100
F 0 "C3" H 3410 2170 50  0000 L CNN
F 1 "22u" H 3410 2020 50  0000 L CNN
F 2 "Discret:C1V8" H 3400 2100 50  0001 C CNN
F 3 "" H 3400 2100 50  0000 C CNN
	1    3400 2100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5743011C
P 8050 5000
F 0 "#PWR04" H 8050 4750 50  0001 C CNN
F 1 "GND" H 8050 4850 50  0000 C CNN
F 2 "" H 8050 5000 50  0000 C CNN
F 3 "" H 8050 5000 50  0000 C CNN
	1    8050 5000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 57430287
P 8750 5000
F 0 "#PWR05" H 8750 4750 50  0001 C CNN
F 1 "GND" H 8750 4850 50  0000 C CNN
F 2 "" H 8750 5000 50  0000 C CNN
F 3 "" H 8750 5000 50  0000 C CNN
	1    8750 5000
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 57430BA3
P 8550 2250
F 0 "#PWR06" H 8550 2100 50  0001 C CNN
F 1 "+5V" H 8550 2390 50  0000 C CNN
F 2 "" H 8550 2250 50  0000 C CNN
F 3 "" H 8550 2250 50  0000 C CNN
	1    8550 2250
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P4
U 1 1 57430DFD
P 9150 3300
F 0 "P4" H 9150 3500 50  0000 C CNN
F 1 "CONN_01X03" V 9250 3300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 9150 3300 50  0001 C CNN
F 3 "" H 9150 3300 50  0000 C CNN
	1    9150 3300
	1    0    0    -1  
$EndComp
Text Label 6900 4200 0    60   ~ 0
D0
Text Label 6900 4300 0    60   ~ 0
D1
Text Label 6900 4400 0    60   ~ 0
D2
Text Label 6900 4500 0    60   ~ 0
D3
Text Label 6900 4600 0    60   ~ 0
D4
Text Label 6900 4700 0    60   ~ 0
D5
Text Label 6900 4800 0    60   ~ 0
D6
Text Label 6900 4900 0    60   ~ 0
D7
Text Label 6950 3000 0    60   ~ 0
A1
Text Label 6950 2800 0    60   ~ 0
nRST
Text Label 6950 2700 0    60   ~ 0
nTUBE
Text Label 6950 2600 0    60   ~ 0
PHI2
Text Label 6950 2500 0    60   ~ 0
RnW
$Comp
L GND #PWR07
U 1 1 574353E3
P 3050 2450
F 0 "#PWR07" H 3050 2200 50  0001 C CNN
F 1 "GND" H 3050 2300 50  0000 C CNN
F 2 "" H 3050 2450 50  0000 C CNN
F 3 "" H 3050 2450 50  0000 C CNN
	1    3050 2450
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR08
U 1 1 57436229
P 3050 1800
F 0 "#PWR08" H 3050 1650 50  0001 C CNN
F 1 "VCC" H 3050 1950 50  0000 C CNN
F 2 "" H 3050 1800 50  0000 C CNN
F 3 "" H 3050 1800 50  0000 C CNN
	1    3050 1800
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR09
U 1 1 574365F4
P 7900 2900
F 0 "#PWR09" H 7900 2750 50  0001 C CNN
F 1 "VCC" H 7900 3050 50  0000 C CNN
F 2 "" H 7900 2900 50  0000 C CNN
F 3 "" H 7900 2900 50  0000 C CNN
	1    7900 2900
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG010
U 1 1 57437A79
P 2050 2400
F 0 "#FLG010" H 2050 2495 50  0001 C CNN
F 1 "PWR_FLAG" H 2050 2580 50  0000 C CNN
F 2 "" H 2050 2400 50  0000 C CNN
F 3 "" H 2050 2400 50  0000 C CNN
	1    2050 2400
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR011
U 1 1 57437ABF
P 2050 2200
F 0 "#PWR011" H 2050 2050 50  0001 C CNN
F 1 "+5V" H 2050 2340 50  0000 C CNN
F 2 "" H 2050 2200 50  0000 C CNN
F 3 "" H 2050 2200 50  0000 C CNN
	1    2050 2200
	1    0    0    -1  
$EndComp
$Comp
L 74LS245 U1
U 1 1 5743815B
P 6150 2700
F 0 "U1" H 6250 3275 50  0000 L BNN
F 1 "74LVC245AN" H 6200 2125 50  0000 L TNN
F 2 "Housings_DIP:DIP-20_W7.62mm" H 6150 2700 50  0001 C CNN
F 3 "" H 6150 2700 50  0000 C CNN
	1    6150 2700
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG012
U 1 1 574383D9
P 2550 2400
F 0 "#FLG012" H 2550 2495 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 2580 50  0000 C CNN
F 2 "" H 2550 2400 50  0000 C CNN
F 3 "" H 2550 2400 50  0000 C CNN
	1    2550 2400
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG013
U 1 1 5743841F
P 2550 1800
F 0 "#FLG013" H 2550 1895 50  0001 C CNN
F 1 "PWR_FLAG" H 2550 1980 50  0000 C CNN
F 2 "" H 2550 1800 50  0000 C CNN
F 3 "" H 2550 1800 50  0000 C CNN
	1    2550 1800
	1    0    0    -1  
$EndComp
Text Label 6950 3100 0    60   ~ 0
A2
Text Label 6950 2900 0    60   ~ 0
A0
$Comp
L CONN_02X20 P2
U 1 1 574468E6
P 8400 3950
F 0 "P2" H 8400 5000 50  0000 C CNN
F 1 "CONN_02X20" V 8400 3950 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x20" H 8400 3000 50  0001 C CNN
F 3 "" H 8400 3000 50  0000 C CNN
	1    8400 3950
	1    0    0    -1  
$EndComp
NoConn ~ 8150 4300
NoConn ~ 8150 4500
NoConn ~ 8150 4600
NoConn ~ 8150 4700
NoConn ~ 8150 4800
NoConn ~ 8650 4900
NoConn ~ 8650 4800
NoConn ~ 8650 4700
NoConn ~ 8650 4500
NoConn ~ 8650 4300
Text Label 5250 3200 0    60   ~ 0
TA3
Text Label 6950 3200 0    60   ~ 0
A3
$Comp
L CONN_01X02 P3
U 1 1 5780E2C1
P 8250 2400
F 0 "P3" H 8250 2550 50  0000 C CNN
F 1 "CONN_01X02" V 8350 2400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 8250 2400 50  0001 C CNN
F 3 "" H 8250 2400 50  0000 C CNN
	1    8250 2400
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 2900 4600 5000
Connection ~ 8050 4900
Wire Wire Line
	8050 4900 8150 4900
Connection ~ 8750 4600
Wire Wire Line
	8750 4600 8650 4600
Connection ~ 8750 4400
Wire Wire Line
	8750 4400 8650 4400
Wire Wire Line
	7450 5450 7450 4800
Wire Wire Line
	9150 5450 7450 5450
Wire Wire Line
	9150 3800 9150 5450
Wire Wire Line
	8650 3800 9150 3800
Wire Wire Line
	7450 4800 6800 4800
Wire Wire Line
	4200 3700 6900 3700
Connection ~ 4200 3700
Wire Wire Line
	4200 4000 3300 4000
Wire Wire Line
	7450 3100 7450 3200
Wire Wire Line
	7450 3200 8150 3200
Connection ~ 2700 2300
Wire Wire Line
	2550 2400 2550 2300
Connection ~ 2700 1900
Wire Wire Line
	2550 1800 2550 1900
Wire Wire Line
	8550 2350 8550 2250
Wire Wire Line
	8450 2350 8550 2350
Wire Wire Line
	2050 2200 2050 2400
Wire Wire Line
	3050 1800 3050 2000
Wire Wire Line
	3050 2200 3050 2450
Wire Wire Line
	3300 5200 5000 5200
Wire Wire Line
	3300 5100 4800 5100
Wire Wire Line
	3300 4100 4400 4100
Wire Wire Line
	7550 2600 6850 2600
Wire Wire Line
	9500 1900 7550 1900
Wire Wire Line
	9500 4200 9500 1900
Wire Wire Line
	8650 4200 9500 4200
Wire Wire Line
	7650 4200 6800 4200
Wire Wire Line
	7650 5250 7650 4200
Wire Wire Line
	8950 5250 7650 5250
Wire Wire Line
	8950 4100 8950 5250
Wire Wire Line
	8650 4100 8950 4100
Wire Wire Line
	7350 4900 6800 4900
Wire Wire Line
	7350 5550 7350 4900
Wire Wire Line
	9250 5550 7350 5550
Wire Wire Line
	9250 4000 9250 5550
Wire Wire Line
	8650 4000 9250 4000
Wire Wire Line
	7550 4700 6800 4700
Wire Wire Line
	7550 5350 7550 4700
Wire Wire Line
	9050 5350 7550 5350
Wire Wire Line
	9050 3700 9050 5350
Wire Wire Line
	8650 3700 9050 3700
Wire Wire Line
	7650 2500 6850 2500
Wire Wire Line
	7650 2000 7650 2500
Wire Wire Line
	9400 2000 7650 2000
Wire Wire Line
	9400 3600 9400 2000
Wire Wire Line
	8900 3600 9400 3600
Wire Wire Line
	8900 3500 8900 3600
Wire Wire Line
	8650 3500 8900 3500
Wire Wire Line
	7450 4500 6800 4500
Wire Wire Line
	7450 4100 7450 4500
Wire Wire Line
	8150 4100 7450 4100
Wire Wire Line
	7350 4300 6800 4300
Wire Wire Line
	7350 4000 7350 4300
Wire Wire Line
	8150 4000 7350 4000
Wire Wire Line
	7250 4400 6800 4400
Wire Wire Line
	7250 3900 7250 4400
Wire Wire Line
	8150 3900 7250 3900
Wire Wire Line
	7550 4600 6800 4600
Wire Wire Line
	7550 3700 7550 4600
Wire Wire Line
	8150 3700 7550 3700
Wire Wire Line
	7350 2900 7350 3600
Wire Wire Line
	7350 3600 8150 3600
Wire Wire Line
	7750 2700 6850 2700
Wire Wire Line
	7750 2700 7750 3500
Wire Wire Line
	7750 3500 8150 3500
Wire Wire Line
	7650 2800 6850 2800
Wire Wire Line
	7650 2800 7650 3300
Wire Wire Line
	7650 3300 8150 3300
Wire Wire Line
	8950 3400 8650 3400
Wire Wire Line
	8650 3300 8950 3300
Connection ~ 8750 3200
Connection ~ 8750 3000
Wire Wire Line
	8450 2450 8750 2450
Wire Wire Line
	8750 3000 8650 3000
Wire Wire Line
	8750 2450 8750 3100
Wire Wire Line
	8750 3100 8650 3100
Wire Wire Line
	7900 3000 8150 3000
Connection ~ 8750 3600
Wire Wire Line
	8650 3200 8950 3200
Connection ~ 8750 3900
Wire Wire Line
	8750 3600 8650 3600
Wire Wire Line
	8750 3900 8650 3900
Wire Wire Line
	8750 3200 8750 5000
Connection ~ 8050 4200
Wire Wire Line
	8150 3400 8050 3400
Wire Wire Line
	8050 4200 8150 4200
Wire Wire Line
	8050 3400 8050 5000
Connection ~ 3050 1900
Wire Wire Line
	3400 1900 3400 2000
Wire Wire Line
	2550 1900 3400 1900
Wire Wire Line
	2700 2000 2700 1900
Wire Wire Line
	2700 2300 2700 2200
Connection ~ 3050 2300
Wire Wire Line
	3400 2300 3400 2200
Wire Wire Line
	2550 2300 3400 2300
Wire Wire Line
	3900 3700 3300 3700
Connection ~ 3900 3600
Wire Wire Line
	7000 3600 3900 3600
Wire Wire Line
	6900 3700 6900 3900
Wire Wire Line
	6900 3900 6800 3900
Wire Wire Line
	7000 4000 6800 4000
Wire Wire Line
	7000 3600 7000 4000
Connection ~ 6950 2200
Wire Wire Line
	6950 2050 6950 2300
Wire Wire Line
	6950 2300 6850 2300
Wire Wire Line
	6850 2200 6950 2200
Wire Wire Line
	4800 5100 4800 3000
Wire Wire Line
	4600 5000 3300 5000
Wire Wire Line
	3300 4900 5400 4900
Wire Wire Line
	3300 4800 5400 4800
Wire Wire Line
	3300 4700 5400 4700
Wire Wire Line
	3300 4600 5400 4600
Wire Wire Line
	3300 4500 5400 4500
Wire Wire Line
	3300 4400 5400 4400
Wire Wire Line
	3300 4300 5400 4300
Wire Wire Line
	3300 4200 5400 4200
Connection ~ 2550 5600
Wire Wire Line
	2300 5600 2300 5400
Connection ~ 2550 3700
Wire Wire Line
	2300 3700 2300 3850
Connection ~ 2550 5300
Wire Wire Line
	2800 5300 2550 5300
Connection ~ 2550 5400
Wire Wire Line
	2550 5400 2800 5400
Connection ~ 2550 5500
Wire Wire Line
	2550 5500 2800 5500
Wire Wire Line
	2300 5600 2800 5600
Wire Wire Line
	2550 5200 2550 5600
Wire Wire Line
	2800 5200 2550 5200
Connection ~ 2550 3800
Wire Wire Line
	2800 3800 2550 3800
Connection ~ 2550 3900
Wire Wire Line
	2550 3900 2800 3900
Connection ~ 2550 4000
Wire Wire Line
	2550 4000 2800 4000
Connection ~ 2550 4100
Wire Wire Line
	2550 4100 2800 4100
Connection ~ 2550 4200
Wire Wire Line
	2550 4200 2800 4200
Connection ~ 2550 4300
Wire Wire Line
	2550 4300 2800 4300
Connection ~ 2550 4400
Wire Wire Line
	2550 4400 2800 4400
Connection ~ 2550 4500
Wire Wire Line
	2550 4500 2800 4500
Connection ~ 2550 4600
Wire Wire Line
	2550 4600 2800 4600
Connection ~ 2550 4700
Wire Wire Line
	2550 4700 2800 4700
Connection ~ 2550 4800
Wire Wire Line
	2550 4800 2800 4800
Connection ~ 2550 4900
Wire Wire Line
	2550 4900 2800 4900
Connection ~ 2550 5000
Wire Wire Line
	2550 5000 2800 5000
Wire Wire Line
	2550 5100 2800 5100
Wire Wire Line
	2550 3700 2550 5100
Wire Wire Line
	2300 3700 2800 3700
Wire Wire Line
	4400 2800 5450 2800
Wire Wire Line
	4400 4100 4400 2800
Wire Wire Line
	4200 2700 5450 2700
Wire Wire Line
	4200 2700 4200 4000
Wire Wire Line
	4000 2600 5450 2600
Wire Wire Line
	4000 2600 4000 3800
Wire Wire Line
	4000 3800 3300 3800
Wire Wire Line
	3900 2500 5450 2500
Wire Wire Line
	3900 2500 3900 3700
Wire Wire Line
	3300 5300 5200 5300
Wire Wire Line
	5200 5300 5200 3200
Wire Wire Line
	7550 1900 7550 2600
Wire Wire Line
	8150 4400 7750 4400
Wire Wire Line
	7750 4400 7750 3800
Wire Wire Line
	7750 3800 7250 3800
Wire Wire Line
	7250 3800 7250 3200
Wire Wire Line
	5200 3200 5450 3200
Wire Wire Line
	5000 3100 5450 3100
Wire Wire Line
	5000 5200 5000 3100
Wire Wire Line
	4800 3000 5450 3000
Wire Wire Line
	5450 2900 4600 2900
Wire Wire Line
	6850 2900 7350 2900
Wire Wire Line
	7250 3200 6850 3200
Wire Wire Line
	7450 3100 6850 3100
Wire Wire Line
	8150 3100 7550 3100
Wire Wire Line
	7550 3100 7550 3000
Wire Wire Line
	7550 3000 6850 3000
Wire Wire Line
	7900 3000 7900 2900
NoConn ~ 8150 3800
$EndSCHEMATC
