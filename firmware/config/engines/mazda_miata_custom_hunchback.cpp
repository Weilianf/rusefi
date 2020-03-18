/*
 * @file mazda_miata_custom_hunchback.cpp
 *
 * rusEfi Green Race car - based on NA6 body with VVT swap
 *
 * Hunchback - VVT engine with NA fuel rail
 * set engine_type 54
 *
 * It's using ZM-DE 2000 protege 36/1 trigger wheel ZM 01-11-408 and there are some minor issues :(
 *
 * MAZDA_MIATA_2003_NA_RAIL
 *
 * @date Sep 20, 2019
 * @author Andrey Belomutskiy, (c) 2012-2020
 */

#include "mazda_miata_vvt.h"
#include "custom_engine.h"
#include "fsio_impl.h"
#include "ego.h"
#include "thermistors.h"

EXTERN_CONFIG;

// todo: why would this not work?
//extern const float mazda_miata_nb2_RpmBins[FUEL_RPM_COUNT];
//extern const float mazda_miata_nb2_LoadBins[FUEL_LOAD_COUNT];

const float mazda_miata_nb2_RpmBins[FUEL_RPM_COUNT] = {700.0, 820.0, 950.0, 1100.0,
		1300.0, 1550.0, 1800.0, 2150.0,
		2500.0, 3000.0, 3500.0, 4150.0,
		4900.0, 5800.0, 6800.0, 8000.0}
;

const float mazda_miata_nb2_LoadBins[FUEL_LOAD_COUNT] = {20.0, 25.0, 30.0, 35.0,
		40.0, 46.0, 54.0, 63.0,
		73.0, 85.0, 99.0, 116.0,
		135.0, 158.0, 185.0, 220.0}
;

static float const fsio_table_dyno[FSIO_TABLE_8][FSIO_TABLE_8] = {
		/* Generated by TS2C on Sun May 07 09:35:13 EDT 2017*/
		{/* 0 30.000	*//* 0 700.0*/1.000,	/* 1 1000.0*/3.000,	/* 2 2000.0*/10.000,	/* 3 3000.0*/20.000,	/* 4 3500.0*/20.000,	/* 5 4500.0*/16.000,	/* 6 5500.0*/11.000,	/* 7 6500.0*/10.000,	},
		{/* 1 40.000	*//* 0 700.0*/3.000,	/* 1 1000.0*/10.000,	/* 2 2000.0*/19.000,	/* 3 3000.0*/26.000,	/* 4 3500.0*/20.000,	/* 5 4500.0*/16.000,	/* 6 5500.0*/11.000,	/* 7 6500.0*/10.000,	},
		{/* 2 50.000	*//* 0 700.0*/7.000,	/* 1 1000.0*/16.000,	/* 2 2000.0*/24.000,	/* 3 3000.0*/28.000,	/* 4 3500.0*/20.000,	/* 5 4500.0*/16.000,	/* 6 5500.0*/11.000,	/* 7 6500.0*/10.000,	},
		{/* 3 60.000	*//* 0 700.0*/11.000,	/* 1 1000.0*/20.000,	/* 2 2000.0*/27.000,	/* 3 3000.0*/28.000,	/* 4 3500.0*/20.000,	/* 5 4500.0*/16.000,	/* 6 5500.0*/11.000,	/* 7 6500.0*/10.000,	},
		{/* 4 70.000	*//* 0 700.0*/13.000,	/* 1 1000.0*/24.000,	/* 2 2000.0*/31.000,	/* 3 3000.0*/28.000,	/* 4 3500.0*/20.000,	/* 5 4500.0*/16.000,	/* 6 5500.0*/11.000,	/* 7 6500.0*/10.000,	},
		{/* 5 75.000	*//* 0 700.0*/15.000,	/* 1 1000.0*/27.000,	/* 2 2000.0*/33.000,	/* 3 3000.0*/28.000,	/* 4 3500.0*/20.000,	/* 5 4500.0*/16.000,	/* 6 5500.0*/11.000,	/* 7 6500.0*/10.000,	},
		{/* 6 82.000	*//* 0 700.0*/17.000,	/* 1 1000.0*/28.000,	/* 2 2000.0*/33.000,	/* 3 3000.0*/28.000,	/* 4 3500.0*/20.000,	/* 5 4500.0*/16.000,	/* 6 5500.0*/11.000,	/* 7 6500.0*/10.000,	},
		{/* 7 85.000	*//* 0 700.0*/17.000,	/* 1 1000.0*/28.000,	/* 2 2000.0*/33.000,	/* 3 3000.0*/28.000,	/* 4 3500.0*/20.000,	/* 5 4500.0*/16.000,	/* 6 5500.0*/11.000,	/* 7 6500.0*/10.000,	},
};

#if DEFAULT_FUEL_LOAD_COUNT == FUEL_LOAD_COUNT
static const fuel_table_t mapBased18vvtVeTable_NA_fuel_rail = {
		/* Generated by TS2C on Sun May 07 09:37:15 EDT 2017*/
		{/* 0 20.000	*//* 0 700.0*/35.685,	/* 1 820.0*/36.982,	/* 2 950.0*/37.200,	/* 3 1100.0*/35.796,	/* 4 1300.0*/36.149,	/* 5 1550.0*/42.781,	/* 6 1800.0*/45.281,	/* 7 2150.0*/34.447,	/* 8 2500.0*/26.662,	/* 9 3000.0*/27.834,	/* 10 3500.0*/29.178,	/* 11 4150.0*/32.136,	/* 12 4900.0*/36.009,	/* 13 5800.0*/32.815,	/* 14 6800.0*/34.415,	/* 15 8000.0*/36.896,	},
		{/* 1 25.000	*//* 0 700.0*/35.593,	/* 1 820.0*/38.290,	/* 2 950.0*/38.543,	/* 3 1100.0*/44.567,	/* 4 1300.0*/42.543,	/* 5 1550.0*/51.690,	/* 6 1800.0*/50.893,	/* 7 2150.0*/45.882,	/* 8 2500.0*/42.473,	/* 9 3000.0*/41.591,	/* 10 3500.0*/39.830,	/* 11 4150.0*/43.369,	/* 12 4900.0*/38.590,	/* 13 5800.0*/36.461,	/* 14 6800.0*/38.698,	/* 15 8000.0*/40.621,	},
		{/* 2 30.000	*//* 0 700.0*/37.539,	/* 1 820.0*/41.105,	/* 2 950.0*/51.838,	/* 3 1100.0*/48.730,	/* 4 1300.0*/47.475,	/* 5 1550.0*/51.808,	/* 6 1800.0*/49.862,	/* 7 2150.0*/47.648,	/* 8 2500.0*/56.394,	/* 9 3000.0*/51.537,	/* 10 3500.0*/52.022,	/* 11 4150.0*/60.170,	/* 12 4900.0*/59.945,	/* 13 5800.0*/80.000,	/* 14 6800.0*/80.000,	/* 15 8000.0*/80.000,	},
		{/* 3 35.000	*//* 0 700.0*/39.606,	/* 1 820.0*/44.472,	/* 2 950.0*/53.027,	/* 3 1100.0*/50.709,	/* 4 1300.0*/52.243,	/* 5 1550.0*/55.301,	/* 6 1800.0*/55.630,	/* 7 2150.0*/64.738,	/* 8 2500.0*/68.993,	/* 9 3000.0*/57.959,	/* 10 3500.0*/59.814,	/* 11 4150.0*/68.593,	/* 12 4900.0*/66.688,	/* 13 5800.0*/80.000,	/* 14 6800.0*/80.000,	/* 15 8000.0*/80.000,	},
		{/* 4 40.000	*//* 0 700.0*/45.470,	/* 1 820.0*/57.758,	/* 2 950.0*/53.028,	/* 3 1100.0*/47.634,	/* 4 1300.0*/62.921,	/* 5 1550.0*/62.927,	/* 6 1800.0*/63.611,	/* 7 2150.0*/68.833,	/* 8 2500.0*/72.751,	/* 9 3000.0*/63.612,	/* 10 3500.0*/74.939,	/* 11 4150.0*/84.469,	/* 12 4900.0*/75.026,	/* 13 5800.0*/80.000,	/* 14 6800.0*/80.000,	/* 15 8000.0*/80.000,	},
		{/* 5 46.000	*//* 0 700.0*/55.036,	/* 1 820.0*/63.090,	/* 2 950.0*/58.650,	/* 3 1100.0*/53.830,	/* 4 1300.0*/59.599,	/* 5 1550.0*/64.794,	/* 6 1800.0*/67.608,	/* 7 2150.0*/73.556,	/* 8 2500.0*/75.610,	/* 9 3000.0*/82.211,	/* 10 3500.0*/80.998,	/* 11 4150.0*/86.837,	/* 12 4900.0*/91.399,	/* 13 5800.0*/80.000,	/* 14 6800.0*/80.000,	/* 15 8000.0*/80.000,	},
		{/* 6 54.000	*//* 0 700.0*/62.275,	/* 1 820.0*/69.333,	/* 2 950.0*/67.104,	/* 3 1100.0*/63.689,	/* 4 1300.0*/67.871,	/* 5 1550.0*/68.809,	/* 6 1800.0*/77.741,	/* 7 2150.0*/82.000,	/* 8 2500.0*/90.645,	/* 9 3000.0*/96.308,	/* 10 3500.0*/94.651,	/* 11 4150.0*/96.667,	/* 12 4900.0*/92.464,	/* 13 5800.0*/80.000,	/* 14 6800.0*/80.000,	/* 15 8000.0*/80.000,	},
		{/* 7 63.000	*//* 0 700.0*/67.369,	/* 1 820.0*/73.738,	/* 2 950.0*/72.983,	/* 3 1100.0*/73.412,	/* 4 1300.0*/78.288,	/* 5 1550.0*/73.531,	/* 6 1800.0*/79.228,	/* 7 2150.0*/92.174,	/* 8 2500.0*/105.553,	/* 9 3000.0*/105.886,	/* 10 3500.0*/100.172,	/* 11 4150.0*/106.089,	/* 12 4900.0*/103.000,	/* 13 5800.0*/103.000,	/* 14 6800.0*/108.000,	/* 15 8000.0*/108.000,	},
		{/* 8 73.000	*//* 0 700.0*/70.760,	/* 1 820.0*/74.892,	/* 2 950.0*/75.153,	/* 3 1100.0*/79.664,	/* 4 1300.0*/89.987,	/* 5 1550.0*/90.422,	/* 6 1800.0*/95.789,	/* 7 2150.0*/98.367,	/* 8 2500.0*/96.231,	/* 9 3000.0*/100.179,	/* 10 3500.0*/92.473,	/* 11 4150.0*/101.756,	/* 12 4900.0*/103.000,	/* 13 5800.0*/103.000,	/* 14 6800.0*/108.000,	/* 15 8000.0*/108.000,	},
		{/* 9 85.000	*//* 0 700.0*/72.255,	/* 1 820.0*/76.109,	/* 2 950.0*/79.744,	/* 3 1100.0*/80.844,	/* 4 1300.0*/83.493,	/* 5 1550.0*/82.232,	/* 6 1800.0*/85.762,	/* 7 2150.0*/97.047,	/* 8 2500.0*/98.763,	/* 9 3000.0*/104.394,	/* 10 3500.0*/102.008,	/* 11 4150.0*/115.132,	/* 12 4900.0*/103.000,	/* 13 5800.0*/103.000,	/* 14 6800.0*/108.000,	/* 15 8000.0*/108.000,	},
		{/* 10 99.000	*//* 0 700.0*/78.899,	/* 1 820.0*/77.096,	/* 2 950.0*/79.895,	/* 3 1100.0*/76.554,	/* 4 1300.0*/78.057,	/* 5 1550.0*/78.602,	/* 6 1800.0*/83.254,	/* 7 2150.0*/91.812,	/* 8 2500.0*/101.884,	/* 9 3000.0*/108.911,	/* 10 3500.0*/103.629,	/* 11 4150.0*/116.945,	/* 12 4900.0*/108.542,	/* 13 5800.0*/103.625,	/* 14 6800.0*/108.000,	/* 15 8000.0*/108.000,	},
		{/* 11 116.000	*//* 0 700.0*/80.000,	/* 1 820.0*/80.000,	/* 2 950.0*/80.000,	/* 3 1100.0*/80.000,	/* 4 1300.0*/80.000,	/* 5 1550.0*/80.000,	/* 6 1800.0*/80.000,	/* 7 2150.0*/100.000,	/* 8 2500.0*/100.000,	/* 9 3000.0*/100.000,	/* 10 3500.0*/106.000,	/* 11 4150.0*/116.600,	/* 12 4900.0*/108.000,	/* 13 5800.0*/108.000,	/* 14 6800.0*/108.000,	/* 15 8000.0*/108.000,	},
		{/* 12 135.000	*//* 0 700.0*/80.000,	/* 1 820.0*/80.000,	/* 2 950.0*/80.000,	/* 3 1100.0*/80.000,	/* 4 1300.0*/80.000,	/* 5 1550.0*/80.000,	/* 6 1800.0*/80.000,	/* 7 2150.0*/100.000,	/* 8 2500.0*/100.000,	/* 9 3000.0*/100.000,	/* 10 3500.0*/106.000,	/* 11 4150.0*/116.600,	/* 12 4900.0*/108.000,	/* 13 5800.0*/108.000,	/* 14 6800.0*/108.000,	/* 15 8000.0*/108.000,	},
		{/* 13 158.000	*//* 0 700.0*/80.000,	/* 1 820.0*/80.000,	/* 2 950.0*/80.000,	/* 3 1100.0*/80.000,	/* 4 1300.0*/80.000,	/* 5 1550.0*/80.000,	/* 6 1800.0*/80.000,	/* 7 2150.0*/80.000,	/* 8 2500.0*/80.000,	/* 9 3000.0*/80.000,	/* 10 3500.0*/80.000,	/* 11 4150.0*/80.000,	/* 12 4900.0*/80.000,	/* 13 5800.0*/80.000,	/* 14 6800.0*/80.000,	/* 15 8000.0*/80.000,	},
		{/* 14 185.000	*//* 0 700.0*/80.000,	/* 1 820.0*/80.000,	/* 2 950.0*/80.000,	/* 3 1100.0*/80.000,	/* 4 1300.0*/80.000,	/* 5 1550.0*/80.000,	/* 6 1800.0*/80.000,	/* 7 2150.0*/80.000,	/* 8 2500.0*/80.000,	/* 9 3000.0*/80.000,	/* 10 3500.0*/80.000,	/* 11 4150.0*/80.000,	/* 12 4900.0*/80.000,	/* 13 5800.0*/80.000,	/* 14 6800.0*/80.000,	/* 15 8000.0*/80.000,	},
		{/* 15 220.000	*//* 0 700.0*/80.000,	/* 1 820.0*/80.000,	/* 2 950.0*/80.000,	/* 3 1100.0*/80.000,	/* 4 1300.0*/80.000,	/* 5 1550.0*/80.000,	/* 6 1800.0*/80.000,	/* 7 2150.0*/80.000,	/* 8 2500.0*/80.000,	/* 9 3000.0*/80.000,	/* 10 3500.0*/80.000,	/* 11 4150.0*/80.000,	/* 12 4900.0*/80.000,	/* 13 5800.0*/80.000,	/* 14 6800.0*/80.000,	/* 15 8000.0*/80.000,	},
};
#endif

static const  float mazda_miata_nb2_targetAfrRpmBins[FUEL_RPM_COUNT] = {650.0, 800.0, 1050.0, 1300.0,
		1550.0, 1800.0, 2050.0, 2300.0,
		2550.0, 2800.0, 3050.0, 3300.0,
		3550.0, 3800.0, 4050.0, 6400.0}
;

static const float mazda_miata_nb2_targetAfrLoadBins[FUEL_LOAD_COUNT] = {10.0, 20.0, 30.0, 40.0,
		50.0, 60.0, 70.0, 80.0,
		90.0, 100.0, 110.0, 120.0,
		130.0, 140.0, 150.0, 160.0};

static const fuel_table_t target_AFR_hunchback = {
		/* Generated by TS2C on Sun May 07 09:48:38 EDT 2017*/
		{/* 0 10.000	*//* 0 650.0*/14.000,	/* 1 800.0*/14.000,	/* 2 1050.0*/14.000,	/* 3 1300.0*/14.000,	/* 4 1550.0*/14.000,	/* 5 1800.0*/14.000,	/* 6 2050.0*/14.000,	/* 7 2300.0*/14.000,	/* 8 2550.0*/14.000,	/* 9 2800.0*/14.000,	/* 10 3050.0*/14.000,	/* 11 3300.0*/14.000,	/* 12 3550.0*/14.000,	/* 13 3800.0*/14.000,	/* 14 4050.0*/14.000,	/* 15 6400.0*/14.000,	},
		{/* 1 20.000	*//* 0 650.0*/14.000,	/* 1 800.0*/14.000,	/* 2 1050.0*/14.000,	/* 3 1300.0*/14.000,	/* 4 1550.0*/14.000,	/* 5 1800.0*/14.000,	/* 6 2050.0*/14.000,	/* 7 2300.0*/14.000,	/* 8 2550.0*/14.000,	/* 9 2800.0*/14.000,	/* 10 3050.0*/14.000,	/* 11 3300.0*/14.000,	/* 12 3550.0*/14.000,	/* 13 3800.0*/14.000,	/* 14 4050.0*/14.000,	/* 15 6400.0*/14.000,	},
		{/* 2 30.000	*//* 0 650.0*/14.000,	/* 1 800.0*/14.000,	/* 2 1050.0*/14.000,	/* 3 1300.0*/14.000,	/* 4 1550.0*/14.000,	/* 5 1800.0*/14.000,	/* 6 2050.0*/14.000,	/* 7 2300.0*/14.000,	/* 8 2550.0*/14.000,	/* 9 2800.0*/14.000,	/* 10 3050.0*/14.000,	/* 11 3300.0*/14.000,	/* 12 3550.0*/14.000,	/* 13 3800.0*/14.000,	/* 14 4050.0*/14.000,	/* 15 6400.0*/14.000,	},
		{/* 3 40.000	*//* 0 650.0*/14.000,	/* 1 800.0*/14.000,	/* 2 1050.0*/14.000,	/* 3 1300.0*/14.000,	/* 4 1550.0*/14.000,	/* 5 1800.0*/14.000,	/* 6 2050.0*/14.000,	/* 7 2300.0*/14.000,	/* 8 2550.0*/14.000,	/* 9 2800.0*/14.000,	/* 10 3050.0*/14.000,	/* 11 3300.0*/14.000,	/* 12 3550.0*/14.000,	/* 13 3800.0*/14.000,	/* 14 4050.0*/14.000,	/* 15 6400.0*/14.000,	},
		{/* 4 50.000	*//* 0 650.0*/14.000,	/* 1 800.0*/14.000,	/* 2 1050.0*/14.000,	/* 3 1300.0*/14.000,	/* 4 1550.0*/14.000,	/* 5 1800.0*/14.000,	/* 6 2050.0*/14.000,	/* 7 2300.0*/14.000,	/* 8 2550.0*/14.000,	/* 9 2800.0*/14.000,	/* 10 3050.0*/14.000,	/* 11 3300.0*/14.000,	/* 12 3550.0*/14.000,	/* 13 3800.0*/14.000,	/* 14 4050.0*/14.000,	/* 15 6400.0*/14.000,	},
		{/* 5 60.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 6 70.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 7 80.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 8 90.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 9 100.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 10 110.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 11 120.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 12 130.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 13 140.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 14 150.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
		{/* 15 160.000	*//* 0 650.0*/11.700,	/* 1 800.0*/11.700,	/* 2 1050.0*/11.700,	/* 3 1300.0*/11.700,	/* 4 1550.0*/11.700,	/* 5 1800.0*/11.700,	/* 6 2050.0*/11.700,	/* 7 2300.0*/11.700,	/* 8 2550.0*/11.700,	/* 9 2800.0*/11.700,	/* 10 3050.0*/11.700,	/* 11 3300.0*/11.700,	/* 12 3550.0*/11.700,	/* 13 3800.0*/11.700,	/* 14 4050.0*/11.000,	/* 15 6400.0*/11.000,	},
};

void setMazdaMiata2003EngineConfigurationNaFuelRail(DECLARE_CONFIG_PARAMETER_SIGNATURE) {
	setMazdaMiata2003EngineConfiguration(PASS_CONFIG_PARAMETER_SIGNATURE);

	// todo: there should be a better way?
	for (int loadIndex = 0; loadIndex < FSIO_TABLE_8; loadIndex++) {
			for (int rpmIndex = 0; rpmIndex < FSIO_TABLE_8; rpmIndex++) {
				config->fsioTable1[loadIndex][rpmIndex] = fsio_table_dyno[loadIndex][rpmIndex];
			}
		}
	memcpy(config->veRpmBins, mazda_miata_nb2_RpmBins, sizeof(mazda_miata_nb2_RpmBins));
	memcpy(config->veLoadBins, mazda_miata_nb2_LoadBins, sizeof(mazda_miata_nb2_LoadBins));
	copyFuelTable(mapBased18vvtVeTable_NA_fuel_rail, config->veTable);

	engineConfiguration->vvtOffset = 83; // 2002 green car value

	memcpy(config->afrRpmBins, mazda_miata_nb2_targetAfrRpmBins, sizeof(mazda_miata_nb2_targetAfrRpmBins));
	memcpy(config->afrLoadBins, mazda_miata_nb2_targetAfrLoadBins, sizeof(mazda_miata_nb2_targetAfrLoadBins));
	copyTargetAfrTable(target_AFR_hunchback, config->afrTable);

	engineConfiguration->ignitionPins[2] = GPIOC_7;

	// Frankenso analog #7 pin 3J, W48 top <>W48 bottom jumper, not OEM
	engineConfiguration->afr.hwChannel = EFI_ADC_3; // PA3

	engineConfiguration->mafAdcChannel = EFI_ADC_4; // PA4

	setEgoSensor(ES_14Point7_Free PASS_CONFIG_PARAMETER_SUFFIX);


	// set cranking_fuel 9
	engineConfiguration->cranking.baseFuel = 9; // higher value for return system NA conversion since lower fuel pressure
	engineConfiguration->vbattDividerCoeff = 9.30; // actual value on my new board

	engineConfiguration->useConstantDwellDuringCranking = true;
	engineConfiguration->ignitionDwellForCrankingMs = 8;

	engineConfiguration->vvtOffset = 97;


	engineConfiguration->rpmHardLimit = 7200; // we want to survive the race, but we also want some fun!

	// set idle_position 30
	engineConfiguration->manIdlePosition = 30;
	engineConfiguration->crankingIACposition = 65;
}

