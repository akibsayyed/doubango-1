
/* #line 1 "tsip_parser_header_To.rl" */
/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_header_To.c
 * @brief SIP To/t header.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinysip/headers/tsip_header_To.h"

#include "tinysip/parsers/tsip_parser_uri.h"

#include "tsk_debug.h"
#include "tsk_memory.h"

/**@defgroup tsip_header_To_group SIP To header.
*/

/***********************************
*	Ragel state machine.
*/

/* #line 91 "tsip_parser_header_To.rl" */


int tsip_header_To_tostring(const void* header, tsk_buffer_t* output)
{
	if(header)
	{
		int ret;
		const tsip_header_To_t *To = header;
		if(ret=tsip_uri_serialize(To->uri, 1, 1, output))
		{
			return ret;
		}
		if(To->tag)
		{
			tsk_buffer_appendEx(output, ";tag=%s", To->tag);
		}
	}
	return -1;
}

tsip_header_To_t *tsip_header_To_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsip_header_To_t *hdr_to = TSIP_HEADER_TO_CREATE(0,0,0);
	
	const char *tag_start;

	
/* #line 79 "../src/headers/tsip_header_To.c" */
static const char _tsip_machine_parser_header_To_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 2, 1, 3, 
	2, 1, 4
};

static const short _tsip_machine_parser_header_To_key_offsets[] = {
	0, 0, 2, 7, 10, 31, 32, 34, 
	55, 56, 58, 61, 65, 77, 80, 80, 
	81, 85, 86, 105, 106, 108, 126, 145, 
	150, 151, 153, 157, 176, 177, 179, 198, 
	199, 201, 204, 220, 222, 224, 226, 228, 
	230, 231, 233, 237, 241, 242, 244, 247, 
	253, 271, 278, 286, 294, 302, 304, 311, 
	320, 322, 325, 327, 330, 332, 335, 338, 
	339, 342, 343, 346, 347, 356, 365, 373, 
	381, 389, 397, 399, 405, 414, 423, 432, 
	434, 437, 440, 441, 442, 463, 484, 503, 
	508, 509, 511, 515, 534, 535, 537, 556, 
	574, 591, 609, 613, 614, 616, 632, 634, 
	636, 638, 640, 642, 643, 645, 649, 655, 
	675, 694, 699, 699, 703, 723, 742, 747, 
	767, 785, 803, 809, 815, 821, 827, 833, 
	837, 875, 912, 931, 968, 1004, 1012, 1030, 
	1061, 1093, 1125, 1157, 1177, 1208, 1241, 1263, 
	1286, 1308, 1331, 1353, 1376, 1399, 1418, 1441, 
	1460, 1483, 1502, 1535, 1568, 1600, 1632, 1664, 
	1696, 1716, 1746, 1779, 1812, 1845, 1867, 1890, 
	1913, 1932, 1951, 1990, 2029, 2066, 2085, 2122, 
	2158, 2169, 2181, 2193, 2205, 2211, 2222, 2235, 
	2241, 2248, 2254, 2261, 2267, 2274, 2281, 2286, 
	2293, 2298, 2305, 2310, 2323, 2336, 2348, 2360, 
	2372, 2384, 2390, 2400, 2413, 2426, 2439, 2445, 
	2452, 2459, 2464, 2469, 2490, 2511, 2530, 2535, 
	2555, 2573
};

static const char _tsip_machine_parser_header_To_trans_keys[] = {
	84, 116, 9, 32, 58, 79, 111, 9, 
	32, 58, 9, 13, 32, 33, 34, 37, 
	39, 60, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 96, 97, 122, 10, 
	9, 32, 9, 13, 32, 33, 34, 37, 
	39, 60, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 96, 97, 122, 10, 
	9, 32, 9, 32, 60, 65, 90, 97, 
	122, 9, 32, 43, 58, 45, 46, 48, 
	57, 65, 90, 97, 122, 9, 32, 58, 
	62, 9, 13, 32, 59, 10, 9, 13, 
	32, 33, 37, 39, 84, 116, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 10, 9, 32, 9, 32, 33, 37, 
	39, 84, 116, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 33, 37, 39, 59, 61, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 59, 61, 10, 9, 
	32, 9, 32, 59, 61, 9, 13, 32, 
	33, 34, 37, 39, 91, 126, 42, 43, 
	45, 46, 48, 57, 65, 90, 95, 122, 
	10, 9, 32, 9, 13, 32, 33, 34, 
	37, 39, 91, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 10, 9, 
	32, 9, 32, 34, 9, 13, 34, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 32, 126, -128, -65, -128, -65, 
	-128, -65, -128, -65, -128, -65, 10, 9, 
	32, 9, 13, 32, 59, 9, 13, 32, 
	59, 10, 9, 32, 9, 32, 59, 0, 
	9, 11, 12, 14, 127, 9, 13, 32, 
	33, 37, 39, 59, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 58, 
	48, 57, 65, 70, 97, 102, 58, 93, 
	48, 57, 65, 70, 97, 102, 58, 93, 
	48, 57, 65, 70, 97, 102, 58, 93, 
	48, 57, 65, 70, 97, 102, 58, 93, 
	58, 48, 57, 65, 70, 97, 102, 46, 
	58, 93, 48, 57, 65, 70, 97, 102, 
	48, 57, 46, 48, 57, 48, 57, 46, 
	48, 57, 48, 57, 93, 48, 57, 93, 
	48, 57, 93, 46, 48, 57, 46, 46, 
	48, 57, 46, 46, 58, 93, 48, 57, 
	65, 70, 97, 102, 46, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 58, 93, 48, 
	57, 65, 70, 97, 102, 46, 58, 93, 
	48, 57, 65, 70, 97, 102, 46, 58, 
	93, 48, 57, 65, 70, 97, 102, 46, 
	58, 93, 48, 57, 65, 70, 97, 102, 
	48, 57, 46, 48, 57, 46, 48, 57, 
	46, 58, 9, 13, 32, 33, 37, 39, 
	59, 61, 65, 97, 126, 42, 43, 45, 
	46, 48, 57, 66, 90, 95, 122, 9, 
	13, 32, 33, 37, 39, 59, 61, 71, 
	103, 126, 42, 43, 45, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 33, 
	37, 39, 59, 61, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 59, 61, 10, 9, 32, 9, 
	32, 59, 61, 9, 13, 32, 33, 34, 
	37, 39, 91, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 10, 9, 
	32, 9, 13, 32, 33, 34, 37, 39, 
	91, 126, 42, 43, 45, 46, 48, 57, 
	65, 90, 95, 122, 9, 13, 32, 33, 
	37, 39, 59, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 33, 37, 39, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 37, 39, 60, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 60, 10, 9, 32, 
	9, 13, 34, 92, -64, -33, -32, -17, 
	-16, -9, -8, -5, -4, -3, 32, 126, 
	-128, -65, -128, -65, -128, -65, -128, -65, 
	-128, -65, 10, 9, 32, 9, 13, 32, 
	60, 0, 9, 11, 12, 14, 127, 9, 
	13, 32, 33, 37, 39, 42, 43, 58, 
	126, 45, 46, 48, 57, 65, 90, 95, 
	96, 97, 122, 9, 13, 32, 33, 37, 
	39, 58, 60, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 58, 60, 9, 13, 32, 59, 9, 
	13, 32, 33, 37, 39, 59, 84, 116, 
	126, 42, 43, 45, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 33, 37, 
	39, 59, 61, 126, 42, 43, 45, 46, 
	48, 57, 65, 90, 95, 122, 9, 13, 
	32, 59, 61, 9, 13, 32, 33, 34, 
	37, 39, 59, 91, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 37, 39, 59, 126, 42, 
	43, 45, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 34, 59, 92, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 126, 9, 13, 32, 59, -128, 
	-65, 9, 13, 32, 59, -128, -65, 9, 
	13, 32, 59, -128, -65, 9, 13, 32, 
	59, -128, -65, 9, 13, 32, 59, -128, 
	-65, 9, 13, 32, 59, 9, 13, 32, 
	33, 34, 37, 39, 44, 47, 59, 84, 
	92, 116, 126, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 35, 41, 42, 
	57, 58, 64, 65, 90, 91, 94, 95, 
	122, 123, 125, 9, 13, 32, 33, 34, 
	37, 39, 44, 47, 59, 61, 92, 126, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 35, 41, 42, 57, 58, 64, 
	65, 90, 91, 94, 95, 122, 123, 125, 
	9, 13, 32, 34, 59, 61, 92, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 126, 9, 13, 32, 33, 34, 
	37, 39, 44, 47, 59, 91, 92, 126, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 35, 41, 42, 57, 58, 64, 
	65, 90, 93, 94, 95, 122, 123, 125, 
	9, 13, 32, 33, 34, 37, 39, 44, 
	47, 59, 92, 126, -64, -33, -32, -17, 
	-16, -9, -8, -5, -4, -3, 35, 41, 
	42, 57, 58, 64, 65, 90, 91, 94, 
	95, 122, 123, 125, 9, 13, 32, 59, 
	0, 8, 11, 127, 9, 13, 32, 34, 
	59, 92, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 33, 126, 9, 13, 
	32, 34, 58, 59, 92, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	126, 9, 13, 32, 34, 58, 59, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 46, 58, 59, 92, 
	93, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 47, 48, 57, 60, 
	64, 65, 70, 71, 96, 97, 102, 103, 
	126, 9, 13, 32, 34, 59, 92, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 47, 48, 57, 58, 126, 9, 
	13, 32, 34, 46, 59, 92, -64, -33, 
	-32, -17, -16, -9, -8, -5, -4, -3, 
	33, 47, 48, 57, 58, 126, 9, 13, 
	32, 34, 59, 92, -64, -33, -32, -17, 
	-16, -9, -8, -5, -4, -3, 33, 47, 
	48, 57, 58, 126, 9, 13, 32, 34, 
	46, 59, 92, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 47, 48, 
	57, 58, 126, 9, 13, 32, 34, 59, 
	92, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 47, 48, 57, 58, 
	126, 9, 13, 32, 34, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 58, 126, 
	9, 13, 32, 34, 59, 92, 93, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 47, 48, 57, 58, 126, 9, 
	13, 32, 34, 59, 92, 93, -64, -33, 
	-32, -17, -16, -9, -8, -5, -4, -3, 
	33, 126, 9, 13, 32, 34, 46, 59, 
	92, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 47, 48, 57, 58, 
	126, 9, 13, 32, 34, 46, 59, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 126, 9, 13, 32, 34, 
	46, 59, 92, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 47, 48, 
	57, 58, 126, 9, 13, 32, 34, 46, 
	59, 92, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 33, 126, 9, 13, 
	32, 34, 46, 58, 59, 92, 93, -64, 
	-33, -32, -17, -16, -9, -8, -5, -4, 
	-3, 33, 47, 48, 57, 60, 64, 65, 
	70, 71, 96, 97, 102, 103, 126, 9, 
	13, 32, 34, 46, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 47, 48, 57, 60, 64, 
	65, 70, 71, 96, 97, 102, 103, 126, 
	9, 13, 32, 34, 58, 59, 92, 93, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 126, 9, 13, 32, 34, 
	59, 92, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 33, 47, 48, 57, 
	58, 64, 65, 70, 71, 96, 97, 102, 
	103, 126, 9, 13, 32, 34, 46, 58, 
	59, 92, 93, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 47, 48, 
	57, 60, 64, 65, 70, 71, 96, 97, 
	102, 103, 126, 9, 13, 32, 34, 46, 
	58, 59, 92, 93, -64, -33, -32, -17, 
	-16, -9, -8, -5, -4, -3, 33, 47, 
	48, 57, 60, 64, 65, 70, 71, 96, 
	97, 102, 103, 126, 9, 13, 32, 34, 
	46, 58, 59, 92, 93, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 33, 
	47, 48, 57, 60, 64, 65, 70, 71, 
	96, 97, 102, 103, 126, 9, 13, 32, 
	34, 59, 92, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 47, 48, 
	57, 58, 126, 9, 13, 32, 34, 46, 
	59, 92, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 33, 47, 48, 57, 
	58, 126, 9, 13, 32, 34, 46, 59, 
	92, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 47, 48, 57, 58, 
	126, 9, 13, 32, 34, 46, 59, 92, 
	-64, -33, -32, -17, -16, -9, -8, -5, 
	-4, -3, 33, 126, 9, 13, 32, 34, 
	58, 59, 92, -64, -33, -32, -17, -16, 
	-9, -8, -5, -4, -3, 33, 126, 9, 
	13, 32, 33, 34, 37, 39, 44, 47, 
	59, 61, 65, 92, 97, 126, -64, -33, 
	-32, -17, -16, -9, -8, -5, -4, -3, 
	35, 41, 42, 57, 58, 64, 66, 90, 
	91, 94, 95, 122, 123, 125, 9, 13, 
	32, 33, 34, 37, 39, 44, 47, 59, 
	61, 71, 92, 103, 126, -64, -33, -32, 
	-17, -16, -9, -8, -5, -4, -3, 35, 
	41, 42, 57, 58, 64, 65, 90, 91, 
	94, 95, 122, 123, 125, 9, 13, 32, 
	33, 34, 37, 39, 44, 47, 59, 61, 
	92, 126, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 35, 41, 42, 57, 
	58, 64, 65, 90, 91, 94, 95, 122, 
	123, 125, 9, 13, 32, 34, 59, 61, 
	92, -64, -33, -32, -17, -16, -9, -8, 
	-5, -4, -3, 33, 126, 9, 13, 32, 
	33, 34, 37, 39, 44, 47, 59, 91, 
	92, 126, -64, -33, -32, -17, -16, -9, 
	-8, -5, -4, -3, 35, 41, 42, 57, 
	58, 64, 65, 90, 93, 94, 95, 122, 
	123, 125, 9, 13, 32, 33, 34, 37, 
	39, 44, 47, 59, 92, 126, -64, -33, 
	-32, -17, -16, -9, -8, -5, -4, -3, 
	35, 41, 42, 57, 58, 64, 65, 90, 
	91, 94, 95, 122, 123, 125, 9, 13, 
	32, 58, 59, 48, 57, 65, 70, 97, 
	102, 9, 13, 32, 58, 59, 93, 48, 
	57, 65, 70, 97, 102, 9, 13, 32, 
	58, 59, 93, 48, 57, 65, 70, 97, 
	102, 9, 13, 32, 58, 59, 93, 48, 
	57, 65, 70, 97, 102, 9, 13, 32, 
	58, 59, 93, 9, 13, 32, 58, 59, 
	48, 57, 65, 70, 97, 102, 9, 13, 
	32, 46, 58, 59, 93, 48, 57, 65, 
	70, 97, 102, 9, 13, 32, 59, 48, 
	57, 9, 13, 32, 46, 59, 48, 57, 
	9, 13, 32, 59, 48, 57, 9, 13, 
	32, 46, 59, 48, 57, 9, 13, 32, 
	59, 48, 57, 9, 13, 32, 59, 93, 
	48, 57, 9, 13, 32, 59, 93, 48, 
	57, 9, 13, 32, 59, 93, 9, 13, 
	32, 46, 59, 48, 57, 9, 13, 32, 
	46, 59, 9, 13, 32, 46, 59, 48, 
	57, 9, 13, 32, 46, 59, 9, 13, 
	32, 46, 58, 59, 93, 48, 57, 65, 
	70, 97, 102, 9, 13, 32, 46, 58, 
	59, 93, 48, 57, 65, 70, 97, 102, 
	9, 13, 32, 58, 59, 93, 48, 57, 
	65, 70, 97, 102, 9, 13, 32, 58, 
	59, 93, 48, 57, 65, 70, 97, 102, 
	9, 13, 32, 58, 59, 93, 48, 57, 
	65, 70, 97, 102, 9, 13, 32, 58, 
	59, 93, 48, 57, 65, 70, 97, 102, 
	9, 13, 32, 58, 59, 93, 9, 13, 
	32, 59, 48, 57, 65, 70, 97, 102, 
	9, 13, 32, 46, 58, 59, 93, 48, 
	57, 65, 70, 97, 102, 9, 13, 32, 
	46, 58, 59, 93, 48, 57, 65, 70, 
	97, 102, 9, 13, 32, 46, 58, 59, 
	93, 48, 57, 65, 70, 97, 102, 9, 
	13, 32, 59, 48, 57, 9, 13, 32, 
	46, 59, 48, 57, 9, 13, 32, 46, 
	59, 48, 57, 9, 13, 32, 46, 59, 
	9, 13, 32, 58, 59, 9, 13, 32, 
	33, 37, 39, 59, 61, 65, 97, 126, 
	42, 43, 45, 46, 48, 57, 66, 90, 
	95, 122, 9, 13, 32, 33, 37, 39, 
	59, 61, 71, 103, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 9, 
	13, 32, 33, 37, 39, 59, 61, 126, 
	42, 43, 45, 46, 48, 57, 65, 90, 
	95, 122, 9, 13, 32, 59, 61, 9, 
	13, 32, 33, 34, 37, 39, 59, 91, 
	126, 42, 43, 45, 46, 48, 57, 65, 
	90, 95, 122, 9, 13, 32, 33, 37, 
	39, 59, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 122, 0
};

static const char _tsip_machine_parser_header_To_single_lengths[] = {
	0, 2, 5, 3, 9, 1, 2, 9, 
	1, 2, 3, 0, 4, 3, 0, 1, 
	4, 1, 9, 1, 2, 8, 9, 5, 
	1, 2, 4, 9, 1, 2, 9, 1, 
	2, 3, 4, 0, 0, 0, 0, 0, 
	1, 2, 4, 4, 1, 2, 3, 0, 
	8, 1, 2, 2, 2, 2, 1, 3, 
	0, 1, 0, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 3, 3, 2, 2, 
	2, 2, 2, 0, 3, 3, 3, 0, 
	1, 1, 1, 1, 11, 11, 9, 5, 
	1, 2, 4, 9, 1, 2, 9, 8, 
	7, 8, 4, 1, 2, 4, 0, 0, 
	0, 0, 0, 1, 2, 4, 0, 10, 
	9, 5, 0, 4, 10, 9, 5, 10, 
	8, 6, 4, 4, 4, 4, 4, 4, 
	14, 13, 7, 13, 12, 4, 6, 7, 
	8, 8, 8, 8, 7, 9, 6, 7, 
	6, 7, 6, 7, 7, 7, 7, 7, 
	7, 7, 9, 9, 8, 8, 8, 8, 
	8, 6, 9, 9, 9, 6, 7, 7, 
	7, 7, 15, 15, 13, 7, 13, 12, 
	5, 6, 6, 6, 6, 5, 7, 4, 
	5, 4, 5, 4, 5, 5, 5, 5, 
	5, 5, 5, 7, 7, 6, 6, 6, 
	6, 6, 4, 7, 7, 7, 4, 5, 
	5, 5, 5, 11, 11, 9, 5, 10, 
	8, 0
};

static const char _tsip_machine_parser_header_To_range_lengths[] = {
	0, 0, 0, 0, 6, 0, 0, 6, 
	0, 0, 0, 2, 4, 0, 0, 0, 
	0, 0, 5, 0, 0, 5, 5, 0, 
	0, 0, 0, 5, 0, 0, 5, 0, 
	0, 0, 6, 1, 1, 1, 1, 1, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	5, 3, 3, 3, 3, 0, 3, 3, 
	1, 1, 1, 1, 1, 1, 1, 0, 
	1, 0, 1, 0, 3, 3, 3, 3, 
	3, 3, 0, 3, 3, 3, 3, 1, 
	1, 1, 0, 0, 5, 5, 5, 0, 
	0, 0, 0, 5, 0, 0, 5, 5, 
	5, 5, 0, 0, 0, 6, 1, 1, 
	1, 1, 1, 0, 0, 0, 3, 5, 
	5, 0, 0, 0, 5, 5, 0, 5, 
	5, 6, 1, 1, 1, 1, 1, 0, 
	12, 12, 6, 12, 12, 2, 6, 12, 
	12, 12, 12, 6, 12, 12, 8, 8, 
	8, 8, 8, 8, 8, 6, 8, 6, 
	8, 6, 12, 12, 12, 12, 12, 12, 
	6, 12, 12, 12, 12, 8, 8, 8, 
	6, 6, 12, 12, 12, 6, 12, 12, 
	3, 3, 3, 3, 0, 3, 3, 1, 
	1, 1, 1, 1, 1, 1, 0, 1, 
	0, 1, 0, 3, 3, 3, 3, 3, 
	3, 0, 3, 3, 3, 3, 1, 1, 
	1, 0, 0, 5, 5, 5, 0, 5, 
	5, 0
};

static const short _tsip_machine_parser_header_To_index_offsets[] = {
	0, 0, 3, 9, 13, 29, 31, 34, 
	50, 52, 55, 59, 62, 71, 75, 76, 
	78, 83, 85, 100, 102, 105, 119, 134, 
	140, 142, 145, 150, 165, 167, 170, 185, 
	187, 190, 194, 205, 207, 209, 211, 213, 
	215, 217, 220, 225, 230, 232, 235, 239, 
	243, 257, 262, 268, 274, 280, 283, 288, 
	295, 297, 300, 302, 305, 307, 310, 313, 
	315, 318, 320, 323, 325, 332, 339, 345, 
	351, 357, 363, 366, 370, 377, 384, 391, 
	393, 396, 399, 401, 403, 420, 437, 452, 
	458, 460, 463, 468, 483, 485, 488, 503, 
	517, 530, 544, 549, 551, 554, 565, 567, 
	569, 571, 573, 575, 577, 580, 585, 589, 
	605, 620, 626, 627, 632, 648, 663, 669, 
	685, 699, 712, 718, 724, 730, 736, 742, 
	747, 774, 800, 814, 840, 865, 872, 885, 
	905, 926, 947, 968, 983, 1003, 1025, 1040, 
	1056, 1071, 1087, 1102, 1118, 1134, 1148, 1164, 
	1178, 1194, 1208, 1230, 1252, 1273, 1294, 1315, 
	1336, 1351, 1370, 1392, 1414, 1436, 1451, 1467, 
	1483, 1497, 1511, 1539, 1567, 1593, 1607, 1633, 
	1658, 1667, 1677, 1687, 1697, 1704, 1713, 1724, 
	1730, 1737, 1743, 1750, 1756, 1763, 1770, 1776, 
	1783, 1789, 1796, 1802, 1813, 1824, 1834, 1844, 
	1854, 1864, 1871, 1879, 1890, 1901, 1912, 1918, 
	1925, 1932, 1938, 1944, 1961, 1978, 1993, 1999, 
	2015, 2029
};

static const unsigned char _tsip_machine_parser_header_To_trans_targs[] = {
	2, 2, 0, 3, 3, 4, 3, 3, 
	0, 3, 3, 4, 0, 4, 5, 4, 
	96, 101, 96, 96, 11, 96, 96, 96, 
	96, 111, 96, 111, 0, 6, 0, 7, 
	7, 0, 7, 8, 7, 96, 101, 96, 
	96, 11, 96, 96, 96, 96, 111, 96, 
	111, 0, 9, 0, 10, 10, 0, 10, 
	10, 11, 0, 12, 12, 0, 13, 13, 
	12, 14, 12, 12, 12, 12, 0, 13, 
	13, 14, 0, 15, 16, 15, 16, 17, 
	16, 18, 0, 217, 0, 18, 19, 18, 
	22, 22, 22, 84, 84, 22, 22, 22, 
	22, 22, 22, 0, 20, 0, 21, 21, 
	0, 21, 21, 22, 22, 22, 84, 84, 
	22, 22, 22, 22, 22, 22, 0, 23, 
	17, 23, 22, 22, 22, 18, 27, 22, 
	22, 22, 22, 22, 22, 0, 23, 24, 
	23, 18, 27, 0, 25, 0, 26, 26, 
	0, 26, 26, 18, 27, 0, 27, 28, 
	27, 48, 34, 48, 48, 49, 48, 48, 
	48, 48, 48, 48, 0, 29, 0, 30, 
	30, 0, 30, 31, 30, 48, 34, 48, 
	48, 49, 48, 48, 48, 48, 48, 48, 
	0, 32, 0, 33, 33, 0, 33, 33, 
	34, 0, 34, 40, 42, 47, 35, 36, 
	37, 38, 39, 34, 0, 34, 0, 35, 
	0, 36, 0, 37, 0, 38, 0, 41, 
	0, 34, 34, 0, 43, 17, 43, 18, 
	0, 43, 44, 43, 18, 0, 45, 0, 
	46, 46, 0, 46, 46, 18, 0, 34, 
	34, 34, 0, 43, 17, 43, 48, 48, 
	48, 18, 48, 48, 48, 48, 48, 48, 
	0, 83, 50, 50, 50, 0, 54, 42, 
	51, 51, 51, 0, 54, 42, 52, 52, 
	52, 0, 54, 42, 53, 53, 53, 0, 
	54, 42, 0, 70, 55, 50, 50, 0, 
	56, 54, 42, 68, 51, 51, 0, 57, 
	0, 58, 66, 0, 59, 0, 60, 64, 
	0, 61, 0, 42, 62, 0, 42, 63, 
	0, 42, 0, 60, 65, 0, 60, 0, 
	58, 67, 0, 58, 0, 56, 54, 42, 
	69, 52, 52, 0, 56, 54, 42, 53, 
	53, 53, 0, 79, 42, 71, 71, 71, 
	0, 75, 42, 72, 72, 72, 0, 75, 
	42, 73, 73, 73, 0, 75, 42, 74, 
	74, 74, 0, 75, 42, 0, 76, 71, 
	71, 0, 56, 75, 42, 77, 72, 72, 
	0, 56, 75, 42, 78, 73, 73, 0, 
	56, 75, 42, 74, 74, 74, 0, 80, 
	0, 56, 81, 0, 56, 82, 0, 56, 
	0, 70, 0, 23, 17, 23, 22, 22, 
	22, 18, 27, 85, 85, 22, 22, 22, 
	22, 22, 22, 0, 23, 17, 23, 22, 
	22, 22, 18, 27, 86, 86, 22, 22, 
	22, 22, 22, 22, 0, 87, 17, 87, 
	22, 22, 22, 18, 91, 22, 22, 22, 
	22, 22, 22, 0, 87, 88, 87, 18, 
	91, 0, 89, 0, 90, 90, 0, 90, 
	90, 18, 91, 0, 91, 92, 91, 95, 
	34, 95, 95, 49, 95, 95, 95, 95, 
	95, 95, 0, 93, 0, 94, 94, 0, 
	94, 31, 94, 95, 34, 95, 95, 49, 
	95, 95, 95, 95, 95, 95, 0, 43, 
	17, 43, 95, 95, 95, 18, 95, 95, 
	95, 95, 95, 95, 0, 97, 99, 97, 
	96, 96, 96, 96, 96, 96, 96, 96, 
	96, 0, 98, 8, 98, 96, 96, 96, 
	11, 96, 96, 96, 96, 96, 96, 0, 
	98, 8, 98, 11, 0, 100, 0, 97, 
	97, 0, 101, 107, 109, 110, 102, 103, 
	104, 105, 106, 101, 0, 101, 0, 102, 
	0, 103, 0, 104, 0, 105, 0, 108, 
	0, 101, 101, 0, 98, 8, 98, 11, 
	0, 101, 101, 101, 0, 112, 99, 112, 
	96, 96, 96, 96, 111, 114, 96, 111, 
	111, 111, 96, 111, 0, 113, 8, 113, 
	96, 96, 96, 114, 11, 96, 96, 96, 
	96, 96, 96, 0, 113, 8, 113, 114, 
	11, 0, 115, 115, 17, 115, 116, 115, 
	116, 17, 116, 117, 117, 117, 116, 211, 
	211, 117, 117, 117, 117, 117, 117, 115, 
	118, 17, 118, 117, 117, 117, 116, 119, 
	117, 117, 117, 117, 117, 117, 115, 118, 
	17, 118, 116, 119, 115, 119, 17, 119, 
	120, 121, 120, 120, 116, 176, 120, 120, 
	120, 120, 120, 120, 115, 115, 17, 115, 
	120, 120, 120, 116, 120, 120, 120, 120, 
	120, 120, 115, 121, 17, 121, 127, 128, 
	133, 122, 123, 124, 125, 126, 121, 115, 
	115, 17, 115, 116, 121, 115, 115, 17, 
	115, 116, 122, 115, 115, 17, 115, 116, 
	123, 115, 115, 17, 115, 116, 124, 115, 
	115, 17, 115, 116, 125, 115, 115, 17, 
	115, 116, 115, 128, 17, 128, 129, 127, 
	129, 129, 121, 121, 128, 170, 133, 170, 
	129, 122, 123, 124, 125, 126, 121, 129, 
	121, 129, 121, 129, 121, 115, 130, 17, 
	130, 129, 127, 129, 129, 121, 121, 128, 
	131, 133, 129, 122, 123, 124, 125, 126, 
	121, 129, 121, 129, 121, 129, 121, 115, 
	130, 17, 130, 127, 128, 131, 133, 122, 
	123, 124, 125, 126, 121, 115, 131, 17, 
	131, 132, 134, 132, 132, 121, 121, 128, 
	135, 133, 132, 122, 123, 124, 125, 126, 
	121, 132, 121, 132, 121, 132, 121, 115, 
	121, 17, 121, 132, 127, 132, 132, 121, 
	121, 128, 133, 132, 122, 123, 124, 125, 
	126, 121, 132, 121, 132, 121, 132, 121, 
	115, 121, 17, 121, 128, 121, 121, 115, 
	121, 17, 121, 127, 128, 133, 122, 123, 
	124, 125, 126, 121, 115, 121, 17, 121, 
	127, 169, 128, 133, 122, 123, 124, 125, 
	126, 121, 136, 121, 136, 121, 136, 121, 
	115, 121, 17, 121, 127, 140, 128, 133, 
	134, 122, 123, 124, 125, 126, 121, 137, 
	121, 137, 121, 137, 121, 115, 121, 17, 
	121, 127, 140, 128, 133, 134, 122, 123, 
	124, 125, 126, 121, 138, 121, 138, 121, 
	138, 121, 115, 121, 17, 121, 127, 140, 
	128, 133, 134, 122, 123, 124, 125, 126, 
	121, 139, 121, 139, 121, 139, 121, 115, 
	121, 17, 121, 127, 140, 128, 133, 134, 
	122, 123, 124, 125, 126, 121, 115, 121, 
	17, 121, 127, 156, 128, 133, 122, 123, 
	124, 125, 126, 121, 141, 121, 136, 121, 
	136, 121, 115, 121, 17, 121, 127, 142, 
	140, 128, 133, 134, 122, 123, 124, 125, 
	126, 121, 154, 121, 137, 121, 137, 121, 
	115, 121, 17, 121, 127, 128, 133, 122, 
	123, 124, 125, 126, 121, 143, 121, 115, 
	121, 17, 121, 127, 144, 128, 133, 122, 
	123, 124, 125, 126, 121, 152, 121, 115, 
	121, 17, 121, 127, 128, 133, 122, 123, 
	124, 125, 126, 121, 145, 121, 115, 121, 
	17, 121, 127, 146, 128, 133, 122, 123, 
	124, 125, 126, 121, 150, 121, 115, 121, 
	17, 121, 127, 128, 133, 122, 123, 124, 
	125, 126, 121, 147, 121, 115, 121, 17, 
	121, 127, 128, 133, 134, 122, 123, 124, 
	125, 126, 121, 148, 121, 115, 121, 17, 
	121, 127, 128, 133, 134, 122, 123, 124, 
	125, 126, 121, 149, 121, 115, 121, 17, 
	121, 127, 128, 133, 134, 122, 123, 124, 
	125, 126, 121, 115, 121, 17, 121, 127, 
	146, 128, 133, 122, 123, 124, 125, 126, 
	121, 151, 121, 115, 121, 17, 121, 127, 
	146, 128, 133, 122, 123, 124, 125, 126, 
	121, 115, 121, 17, 121, 127, 144, 128, 
	133, 122, 123, 124, 125, 126, 121, 153, 
	121, 115, 121, 17, 121, 127, 144, 128, 
	133, 122, 123, 124, 125, 126, 121, 115, 
	121, 17, 121, 127, 142, 140, 128, 133, 
	134, 122, 123, 124, 125, 126, 121, 155, 
	121, 138, 121, 138, 121, 115, 121, 17, 
	121, 127, 142, 140, 128, 133, 134, 122, 
	123, 124, 125, 126, 121, 139, 121, 139, 
	121, 139, 121, 115, 121, 17, 121, 127, 
	165, 128, 133, 134, 122, 123, 124, 125, 
	126, 121, 157, 121, 157, 121, 157, 121, 
	115, 121, 17, 121, 127, 161, 128, 133, 
	134, 122, 123, 124, 125, 126, 121, 158, 
	121, 158, 121, 158, 121, 115, 121, 17, 
	121, 127, 161, 128, 133, 134, 122, 123, 
	124, 125, 126, 121, 159, 121, 159, 121, 
	159, 121, 115, 121, 17, 121, 127, 161, 
	128, 133, 134, 122, 123, 124, 125, 126, 
	121, 160, 121, 160, 121, 160, 121, 115, 
	121, 17, 121, 127, 161, 128, 133, 134, 
	122, 123, 124, 125, 126, 121, 115, 121, 
	17, 121, 127, 128, 133, 122, 123, 124, 
	125, 126, 121, 162, 121, 157, 121, 157, 
	121, 115, 121, 17, 121, 127, 142, 161, 
	128, 133, 134, 122, 123, 124, 125, 126, 
	121, 163, 121, 158, 121, 158, 121, 115, 
	121, 17, 121, 127, 142, 161, 128, 133, 
	134, 122, 123, 124, 125, 126, 121, 164, 
	121, 159, 121, 159, 121, 115, 121, 17, 
	121, 127, 142, 161, 128, 133, 134, 122, 
	123, 124, 125, 126, 121, 160, 121, 160, 
	121, 160, 121, 115, 121, 17, 121, 127, 
	128, 133, 122, 123, 124, 125, 126, 121, 
	166, 121, 115, 121, 17, 121, 127, 142, 
	128, 133, 122, 123, 124, 125, 126, 121, 
	167, 121, 115, 121, 17, 121, 127, 142, 
	128, 133, 122, 123, 124, 125, 126, 121, 
	168, 121, 115, 121, 17, 121, 127, 142, 
	128, 133, 122, 123, 124, 125, 126, 121, 
	115, 121, 17, 121, 127, 156, 128, 133, 
	122, 123, 124, 125, 126, 121, 115, 130, 
	17, 130, 129, 127, 129, 129, 121, 121, 
	128, 131, 171, 133, 171, 129, 122, 123, 
	124, 125, 126, 121, 129, 121, 129, 121, 
	129, 121, 115, 130, 17, 130, 129, 127, 
	129, 129, 121, 121, 128, 131, 172, 133, 
	172, 129, 122, 123, 124, 125, 126, 121, 
	129, 121, 129, 121, 129, 121, 115, 173, 
	17, 173, 129, 127, 129, 129, 121, 121, 
	128, 174, 133, 129, 122, 123, 124, 125, 
	126, 121, 129, 121, 129, 121, 129, 121, 
	115, 173, 17, 173, 127, 128, 174, 133, 
	122, 123, 124, 125, 126, 121, 115, 174, 
	17, 174, 175, 134, 175, 175, 121, 121, 
	128, 135, 133, 175, 122, 123, 124, 125, 
	126, 121, 175, 121, 175, 121, 175, 121, 
	115, 121, 17, 121, 175, 127, 175, 175, 
	121, 121, 128, 133, 175, 122, 123, 124, 
	125, 126, 121, 175, 121, 175, 121, 175, 
	121, 115, 115, 17, 115, 210, 116, 177, 
	177, 177, 115, 115, 17, 115, 181, 116, 
	127, 178, 178, 178, 115, 115, 17, 115, 
	181, 116, 127, 179, 179, 179, 115, 115, 
	17, 115, 181, 116, 127, 180, 180, 180, 
	115, 115, 17, 115, 181, 116, 127, 115, 
	115, 17, 115, 197, 116, 182, 177, 177, 
	115, 115, 17, 115, 183, 181, 116, 127, 
	195, 178, 178, 115, 115, 17, 115, 116, 
	184, 115, 115, 17, 115, 185, 116, 193, 
	115, 115, 17, 115, 116, 186, 115, 115, 
	17, 115, 187, 116, 191, 115, 115, 17, 
	115, 116, 188, 115, 115, 17, 115, 116, 
	127, 189, 115, 115, 17, 115, 116, 127, 
	190, 115, 115, 17, 115, 116, 127, 115, 
	115, 17, 115, 187, 116, 192, 115, 115, 
	17, 115, 187, 116, 115, 115, 17, 115, 
	185, 116, 194, 115, 115, 17, 115, 185, 
	116, 115, 115, 17, 115, 183, 181, 116, 
	127, 196, 179, 179, 115, 115, 17, 115, 
	183, 181, 116, 127, 180, 180, 180, 115, 
	115, 17, 115, 206, 116, 127, 198, 198, 
	198, 115, 115, 17, 115, 202, 116, 127, 
	199, 199, 199, 115, 115, 17, 115, 202, 
	116, 127, 200, 200, 200, 115, 115, 17, 
	115, 202, 116, 127, 201, 201, 201, 115, 
	115, 17, 115, 202, 116, 127, 115, 115, 
	17, 115, 116, 203, 198, 198, 115, 115, 
	17, 115, 183, 202, 116, 127, 204, 199, 
	199, 115, 115, 17, 115, 183, 202, 116, 
	127, 205, 200, 200, 115, 115, 17, 115, 
	183, 202, 116, 127, 201, 201, 201, 115, 
	115, 17, 115, 116, 207, 115, 115, 17, 
	115, 183, 116, 208, 115, 115, 17, 115, 
	183, 116, 209, 115, 115, 17, 115, 183, 
	116, 115, 115, 17, 115, 197, 116, 115, 
	118, 17, 118, 117, 117, 117, 116, 119, 
	212, 212, 117, 117, 117, 117, 117, 117, 
	115, 118, 17, 118, 117, 117, 117, 116, 
	119, 213, 213, 117, 117, 117, 117, 117, 
	117, 115, 214, 17, 214, 117, 117, 117, 
	116, 215, 117, 117, 117, 117, 117, 117, 
	115, 214, 17, 214, 116, 215, 115, 215, 
	17, 215, 216, 121, 216, 216, 116, 176, 
	216, 216, 216, 216, 216, 216, 115, 115, 
	17, 115, 216, 216, 216, 116, 216, 216, 
	216, 216, 216, 216, 115, 0, 0
};

static const char _tsip_machine_parser_header_To_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 11, 0, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 0, 9, 
	9, 9, 0, 0, 0, 9, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 9, 9, 9, 9, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 9, 9, 9, 0, 0, 
	0, 9, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 9, 9, 9, 0, 0, 
	0, 9, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 9, 9, 9, 0, 
	0, 0, 9, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 9, 9, 9, 
	0, 0, 0, 9, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 1, 1, 0, 1, 1, 1, 1, 
	1, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 0, 1, 1, 0, 
	1, 1, 1, 1, 1, 1, 0, 7, 
	7, 7, 0, 0, 0, 7, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 5, 5, 5, 0, 0, 0, 
	5, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 5, 5, 5, 5, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 5, 5, 5, 
	0, 0, 0, 0, 5, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 3, 0, 
	3, 3, 3, 1, 1, 1, 3, 1, 
	1, 1, 1, 1, 1, 1, 1, 0, 
	16, 16, 16, 0, 0, 0, 16, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 3, 0, 0, 3, 3, 3, 
	0, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 16, 16, 16, 
	0, 0, 0, 16, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 3, 0, 0, 3, 3, 
	3, 3, 0, 0, 3, 3, 3, 3, 
	0, 0, 3, 3, 3, 3, 0, 0, 
	3, 3, 3, 3, 0, 0, 16, 16, 
	16, 16, 0, 3, 3, 3, 1, 0, 
	1, 1, 0, 0, 3, 1, 0, 1, 
	1, 0, 0, 0, 0, 0, 0, 1, 
	0, 1, 0, 1, 0, 0, 16, 16, 
	16, 0, 0, 0, 0, 0, 0, 16, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 0, 0, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	16, 16, 16, 0, 0, 0, 0, 0, 
	0, 16, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 3, 0, 0, 0, 
	16, 16, 16, 0, 16, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 3, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 3, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 16, 
	16, 16, 0, 0, 0, 0, 0, 0, 
	16, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 16, 16, 16, 0, 0, 
	0, 0, 0, 0, 16, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 16, 
	16, 16, 0, 0, 0, 0, 0, 0, 
	16, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	3, 3, 1, 0, 1, 1, 0, 0, 
	3, 0, 0, 1, 0, 0, 0, 0, 
	0, 0, 1, 0, 1, 0, 1, 0, 
	0, 13, 13, 13, 0, 0, 0, 0, 
	0, 0, 13, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 3, 0, 
	0, 0, 0, 3, 3, 3, 0, 3, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 3, 0, 0, 0, 0, 0, 3, 
	3, 3, 0, 3, 0, 0, 0, 0, 
	0, 3, 3, 3, 0, 3, 0, 0, 
	3, 3, 3, 0, 3, 0, 0, 0, 
	0, 3, 3, 3, 0, 0, 3, 0, 
	0, 0, 0, 0, 3, 3, 3, 3, 
	0, 0, 3, 3, 3, 0, 3, 0, 
	0, 3, 3, 3, 3, 0, 0, 3, 
	3, 3, 0, 3, 0, 0, 3, 3, 
	3, 3, 0, 0, 3, 3, 3, 3, 
	0, 0, 0, 3, 3, 3, 3, 0, 
	0, 0, 3, 3, 3, 3, 0, 0, 
	3, 3, 3, 0, 3, 0, 0, 3, 
	3, 3, 0, 3, 0, 3, 3, 3, 
	0, 3, 0, 0, 3, 3, 3, 0, 
	3, 0, 3, 3, 3, 0, 0, 3, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 3, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 3, 0, 
	0, 0, 0, 0, 3, 3, 3, 0, 
	3, 0, 0, 0, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 0, 0, 0, 
	3, 3, 3, 0, 3, 0, 0, 3, 
	3, 3, 3, 0, 0, 0, 0, 3, 
	3, 3, 0, 0, 3, 0, 0, 0, 
	0, 0, 3, 3, 3, 0, 0, 3, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	0, 0, 3, 0, 0, 0, 0, 0, 
	3, 3, 3, 3, 0, 0, 3, 3, 
	3, 0, 3, 0, 0, 3, 3, 3, 
	0, 3, 0, 0, 3, 3, 3, 0, 
	3, 0, 3, 3, 3, 0, 3, 0, 
	16, 16, 16, 0, 0, 0, 16, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 16, 16, 16, 0, 0, 0, 16, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 16, 16, 16, 0, 0, 0, 
	16, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 3, 3, 3, 0, 0, 3, 
	3, 3, 1, 0, 1, 1, 3, 0, 
	1, 1, 1, 1, 1, 1, 0, 13, 
	13, 13, 0, 0, 0, 13, 0, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const int tsip_machine_parser_header_To_start = 1;
static const int tsip_machine_parser_header_To_first_final = 217;
static const int tsip_machine_parser_header_To_error = 0;

static const int tsip_machine_parser_header_To_en_main = 1;


/* #line 122 "tsip_parser_header_To.rl" */
	
/* #line 1058 "../src/headers/tsip_header_To.c" */
	{
	cs = tsip_machine_parser_header_To_start;
	}

/* #line 123 "tsip_parser_header_To.rl" */
	
/* #line 1065 "../src/headers/tsip_header_To.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _tsip_machine_parser_header_To_trans_keys + _tsip_machine_parser_header_To_key_offsets[cs];
	_trans = _tsip_machine_parser_header_To_index_offsets[cs];

	_klen = _tsip_machine_parser_header_To_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _tsip_machine_parser_header_To_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _tsip_machine_parser_header_To_trans_targs[_trans];

	if ( _tsip_machine_parser_header_To_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _tsip_machine_parser_header_To_actions + _tsip_machine_parser_header_To_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 50 "tsip_parser_header_To.rl" */
	{
		tag_start = p;
	}
	break;
	case 1:
/* #line 55 "tsip_parser_header_To.rl" */
	{
		int len = (int)(p  - tag_start);
		hdr_to->uri = tsip_uri_parse(tag_start, (size_t)len);
	}
	break;
	case 2:
/* #line 61 "tsip_parser_header_To.rl" */
	{
		TSK_PARSER_SET_STRING(hdr_to->display_name);
	}
	break;
	case 3:
/* #line 66 "tsip_parser_header_To.rl" */
	{
		TSK_PARSER_SET_STRING(hdr_to->tag);
	}
	break;
	case 4:
/* #line 71 "tsip_parser_header_To.rl" */
	{
		TSK_PARSER_ADD_PARAM(TSIP_HEADER_PARAMS(hdr_to));
	}
	break;
	case 5:
/* #line 76 "tsip_parser_header_To.rl" */
	{
	}
	break;
/* #line 1174 "../src/headers/tsip_header_To.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

/* #line 124 "tsip_parser_header_To.rl" */
	
	if( cs < 
/* #line 1190 "../src/headers/tsip_header_To.c" */
217
/* #line 125 "tsip_parser_header_To.rl" */
 )
	{
		TSK_OBJECT_SAFE_FREE(hdr_to);
	}
	
	return hdr_to;
}







//========================================================
//	To header object definition
//

/**@ingroup tsip_header_To_group
*/
static void* tsip_header_To_create(void *self, va_list * app)
{
	tsip_header_To_t *To = self;
	if(To)
	{
		const char* display_name = va_arg(*app, const char *);
		const tsip_uri_t* uri = va_arg(*app, const tsip_uri_t *);
		const char* tag = va_arg(*app, const char *);

		To->display_name = tsk_strdup(display_name);
		if(uri) To->uri = tsk_object_ref((void *)uri);
		To->tag = tsk_strdup(tag);

		TSIP_HEADER(To)->type = tsip_htype_To;
		TSIP_HEADER(To)->tostring = tsip_header_To_tostring;
	}
	else
	{
		TSK_DEBUG_ERROR("Failed to create new To header.");
	}
	return self;
}

/**@ingroup tsip_header_To_group
*/
static void* tsip_header_To_destroy(void *self)
{
	tsip_header_To_t *To = self;
	if(To)
	{
		TSK_FREE(To->display_name);
		TSK_FREE(To->tag);

		TSK_OBJECT_SAFE_FREE(To->uri);
		TSK_OBJECT_SAFE_FREE(TSIP_HEADER_PARAMS(To));
	}
	else TSK_DEBUG_ERROR("Null To header.");

	return self;
}

static const tsk_object_def_t tsip_header_To_def_s = 
{
	sizeof(tsip_header_To_t),
	tsip_header_To_create,
	tsip_header_To_destroy,
	0
};
const void *tsip_header_To_def_t = &tsip_header_To_def_s;