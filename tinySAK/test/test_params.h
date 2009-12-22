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
#ifndef _TEST_PARAMS_H_
#define _TEST_PARAMS_H_

void test_params()
{
	tsk_buffer_t *buffer = TSK_BUFFER_CREATE(0,0);

	tsk_param_t *param1 = tsk_params_parse_param("mamadou=diop", strlen("mamadou=diop"));
	tsk_param_t *param2 = tsk_params_parse_param("project=doubango", strlen("project=doubango"));
	tsk_param_t *param3 = tsk_params_parse_param("license=gpl", strlen("license=gpl"));

	tsk_params_L_t *params = TSK_LIST_CREATE();
	tsk_list_push_back_data(params, (void**)&param1);
	tsk_list_push_back_data(params, (void**)&param2);
	tsk_list_push_back_data(params, (void**)&param3);

	tsk_params_tostring(params, ',', buffer);
	TSK_DEBUG_INFO("Buffer=[%s]", TSK_BUFFER_TO_STRING(buffer));

	TSK_BUFFER_SAFE_FREE(buffer);
	TSK_LIST_SAFE_FREE(params);
}


#endif /*_TEST_PARAMS_H_ */