/**
* FreeRDP: A Remote Desktop Protocol Implementation
* Static Entry Point Tables
*
* Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
* Copyright 2015 Thincast Technologies GmbH
* Copyright 2015 DI (FH) Martin Haimberger <martin.haimberger@thincast.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "tables.h"
#include "../../channels/client/rdpSourceMode.h"
_RDP_OPTION_TABLE UsingMode = _RDP_REDIRECTOR;

extern UINT audin_DVCPluginEntry();
extern UINT disp_DVCPluginEntry();
extern UINT echo_DVCPluginEntry();
extern UINT rdpei_DVCPluginEntry();
extern UINT tiragfx_DVCPluginEntry();

extern BOOL VCAPITYPE cliprdr_VirtualChannelEntry(PCHANNEL_ENTRY_POINTS);
extern BOOL VCAPITYPE drdynvc_VirtualChannelEntry(PCHANNEL_ENTRY_POINTS);
extern BOOL VCAPITYPE encomsp_VirtualChannelEntry(PCHANNEL_ENTRY_POINTS);
extern BOOL VCAPITYPE rail_VirtualChannelEntry(PCHANNEL_ENTRY_POINTS);
extern BOOL VCAPITYPE tiradr_VirtualChannelEntry(PCHANNEL_ENTRY_POINTS);
extern BOOL VCAPITYPE tirasnd_VirtualChannelEntry(PCHANNEL_ENTRY_POINTS);
extern BOOL VCAPITYPE remdesk_VirtualChannelEntry(PCHANNEL_ENTRY_POINTS);

extern UINT drive_DeviceServiceEntry();
extern UINT printer_DeviceServiceEntry();
extern UINT smartcard_DeviceServiceEntry();


const STATIC_ENTRY CLIENT_DVCPluginEntry_TABLE[] =
{

	//{ "audin", audin_DVCPluginEntry },
	//{ "disp", disp_DVCPluginEntry },
	//{ "echo", echo_DVCPluginEntry },
	//{ "rdpei", rdpei_DVCPluginEntry },
	{ "rdpgfx", tiragfx_DVCPluginEntry },
	{ NULL, NULL }
};
const STATIC_ENTRY CLIENT_VirtualChannelEntry_TABLE[] =
{

	//{ "cliprdr", cliprdr_VirtualChannelEntry },
	{ "drdynvc", drdynvc_VirtualChannelEntry },
	//{ "encomsp", encomsp_VirtualChannelEntry },
	//{ "rail", rail_VirtualChannelEntry },
	{ "rdpdr", tiradr_VirtualChannelEntry },
	{ "rdpsnd", tirasnd_VirtualChannelEntry },
	//{ "remdesk", remdesk_VirtualChannelEntry },
	{ NULL, NULL }
};
const STATIC_ENTRY CLIENT_DeviceServiceEntry_TABLE[] =
{

	//{ "drive", drive_DeviceServiceEntry },
	//{ "printer", printer_DeviceServiceEntry },
	//{ "smartcard", smartcard_DeviceServiceEntry },
	{ NULL, NULL }
};


const STATIC_ENTRY_TABLE CLIENT_STATIC_ENTRY_TABLES[] =
{
	{ "DVCPluginEntry", CLIENT_DVCPluginEntry_TABLE },
	{ "VirtualChannelEntry", CLIENT_VirtualChannelEntry_TABLE },
	{ "DeviceServiceEntry", CLIENT_DeviceServiceEntry_TABLE },
	{ NULL, NULL }
};


extern void winmm_freerdp_audin_client_subsystem_entry();
extern void winmm_freerdp_rdpsnd_client_subsystem_entry();


const STATIC_SUBSYSTEM_ENTRY CLIENT_AUDIN_SUBSYSTEM_TABLE[] =
{
	//{ "winmm", "", winmm_freerdp_audin_client_subsystem_entry },
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_CLIPRDR_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_DISP_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_DRDYNVC_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_DRIVE_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_ECHO_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_ENCOMSP_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_PRINTER_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RAIL_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDPDR_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDPEI_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDPGFX_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_RDPSND_SUBSYSTEM_TABLE[] =
{
#ifndef _WINRT_DLL
	{ "winmm", "", winmm_freerdp_rdpsnd_client_subsystem_entry },
#endif
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_REMDESK_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};
const STATIC_SUBSYSTEM_ENTRY CLIENT_SMARTCARD_SUBSYSTEM_TABLE[] =
{
	{ NULL, NULL, NULL }
};

const STATIC_ADDIN_TABLE CLIENT_STATIC_ADDIN_TABLE[] =
{
	//{ "audin", audin_DVCPluginEntry, CLIENT_AUDIN_SUBSYSTEM_TABLE },
	//{ "cliprdr", cliprdr_VirtualChannelEntry, CLIENT_CLIPRDR_SUBSYSTEM_TABLE },
	//{ "disp", disp_DVCPluginEntry, CLIENT_DISP_SUBSYSTEM_TABLE },
	{ "drdynvc", drdynvc_VirtualChannelEntry, CLIENT_DRDYNVC_SUBSYSTEM_TABLE },
	//{ "drive", drive_DeviceServiceEntry, CLIENT_DRIVE_SUBSYSTEM_TABLE },
	//{ "echo", echo_DVCPluginEntry, CLIENT_ECHO_SUBSYSTEM_TABLE },
	//{ "encomsp", encomsp_VirtualChannelEntry, CLIENT_ENCOMSP_SUBSYSTEM_TABLE },
	//{ "printer", printer_DeviceServiceEntry, CLIENT_PRINTER_SUBSYSTEM_TABLE },
	//{ "rail", rail_VirtualChannelEntry, CLIENT_RAIL_SUBSYSTEM_TABLE },
	{ "rdpdr", tiradr_VirtualChannelEntry, CLIENT_RDPDR_SUBSYSTEM_TABLE },
	//{ "rdpei", rdpei_DVCPluginEntry, CLIENT_RDPEI_SUBSYSTEM_TABLE },
	{ "rdpgfx", tiragfx_DVCPluginEntry, CLIENT_RDPGFX_SUBSYSTEM_TABLE },
	{ "rdpsnd", tirasnd_VirtualChannelEntry, CLIENT_RDPSND_SUBSYSTEM_TABLE },
	//{ "remdesk", remdesk_VirtualChannelEntry, CLIENT_REMDESK_SUBSYSTEM_TABLE },
	//{ "smartcard", smartcard_DeviceServiceEntry, CLIENT_SMARTCARD_SUBSYSTEM_TABLE },
	{ NULL, NULL, NULL }
};

