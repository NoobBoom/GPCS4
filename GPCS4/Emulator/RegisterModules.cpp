#include "Emulator.h"
#include "SceModuleSystem.h"
#include "sce_modules.h"


#define REGISTER_MODULE(name) \
if (!pModuleSystem->RegisterModule(name))\
{\
	LOG_ERR("Register module failed: %s", name.szModuleName ? name.szModuleName : "null" );\
	break;\
}

#define ALLOW_OVERRIDE(name) \
pModuleSystem->setModuleOverridability(name, true) \

bool CEmulator::RegisterModules()
{
	bool bRet = false;
	do 
	{
		CSceModuleSystem* pModuleSystem = CSceModuleSystem::GetInstance();
		if (!pModuleSystem)
		{
			break;
		}

		REGISTER_MODULE(g_ExpModuleSceAjm);
		REGISTER_MODULE(g_ExpModuleSceAppContentUtil);
		REGISTER_MODULE(g_ExpModuleSceAudio3d);
		REGISTER_MODULE(g_ExpModuleSceAudioOut);
		REGISTER_MODULE(g_ExpModuleSceCommonDialog);
		REGISTER_MODULE(g_ExpModuleSceErrorDialog);
		REGISTER_MODULE(g_ExpModuleSceFiber);
		REGISTER_MODULE(g_ExpModuleSceFios2);
		REGISTER_MODULE(g_ExpModuleSceGameLiveStreaming);
		REGISTER_MODULE(g_ExpModuleSceGnmDriver);
		REGISTER_MODULE(g_ExpModuleSceHttp);
		REGISTER_MODULE(g_ExpModuleSceIme);
		REGISTER_MODULE(g_ExpModuleSceInvitationDialog);
		REGISTER_MODULE(g_ExpModuleSceJobManager);
		REGISTER_MODULE(g_ExpModuleSceJson);
		REGISTER_MODULE(g_ExpModuleSceLibc);
		REGISTER_MODULE(g_ExpModuleSceLibkernel);
		REGISTER_MODULE(g_ExpModuleSceMouse);
		REGISTER_MODULE(g_ExpModuleSceMsgDialog);
		REGISTER_MODULE(g_ExpModuleSceNet);
		REGISTER_MODULE(g_ExpModuleSceNetCtl);
		REGISTER_MODULE(g_ExpModuleSceNpCommerce);
		REGISTER_MODULE(g_ExpModuleSceNpCommon);
		REGISTER_MODULE(g_ExpModuleSceNpManager);
		REGISTER_MODULE(g_ExpModuleSceNpMatching2);
		REGISTER_MODULE(g_ExpModuleSceNpProfileDialog);
		REGISTER_MODULE(g_ExpModuleSceNpScore);
		REGISTER_MODULE(g_ExpModuleSceNpSignaling);
		REGISTER_MODULE(g_ExpModuleSceNpTrophy);
		REGISTER_MODULE(g_ExpModuleSceNpTus);
		REGISTER_MODULE(g_ExpModuleSceNpWebApi);
		REGISTER_MODULE(g_ExpModuleScePad);
		REGISTER_MODULE(g_ExpModuleScePlayGo);
		REGISTER_MODULE(g_ExpModuleScePlayGoDialog);
		REGISTER_MODULE(g_ExpModuleSceRtc);
		REGISTER_MODULE(g_ExpModuleSceRudp);
		REGISTER_MODULE(g_ExpModuleSceSaveData);
		REGISTER_MODULE(g_ExpModuleSceSaveDataDialog);
		REGISTER_MODULE(g_ExpModuleSceScreenShot);
		REGISTER_MODULE(g_ExpModuleSceSsl);
		REGISTER_MODULE(g_ExpModuleSceSysmodule);
		REGISTER_MODULE(g_ExpModuleSceSystemService);
		REGISTER_MODULE(g_ExpModuleSceUserService);
		REGISTER_MODULE(g_ExpModuleSceVideoOut);
		REGISTER_MODULE(g_ExpModuleSceVideoRecording);

		// TODO: Set libc module&libaray as overridable for linker test only. Remember to 
		// remove this.

		ALLOW_OVERRIDE("libc");
		ALLOW_OVERRIDE("libkernel");
		ALLOW_OVERRIDE("libSceGnmDriver");
		ALLOW_OVERRIDE("libSceLibcInternal");
		ALLOW_OVERRIDE("libScePad");
		ALLOW_OVERRIDE("libSceVideoOut");
		ALLOW_OVERRIDE("libSceMbus");
		ALLOW_OVERRIDE("libSceRegMgr");
		ALLOW_OVERRIDE("libSceAvSetting");
		ALLOW_OVERRIDE("libSceFios2");
		ALLOW_OVERRIDE("libSceSysmodule");

		//pModuleSystem->setLibraryOverridability("libc", "libc", true);
		//pModuleSystem->setModuleOverridability("libkernel", true);
		//pModuleSystem->setModuleOverridability("libSceGnmDriver", true);
		//pModuleSystem->setModuleOverridability("libSceLibcInternal", true);
		//pModuleSystem->setModuleOverridability("libScePad", true);
		//pModuleSystem->setModuleOverridability("libSceVideoOut", true);
		//pModuleSystem->setModuleOverridability("libSceMbus.prx", true);

		//pModuleSystem->addAllowedFile("libc.prx");
		//pModuleSystem->addAllowedFile("libkernel.prx");
		//pModuleSystem->addAllowedFile("libSceGnmDriver.prx");
		//pModuleSystem->addAllowedFile("libSceLibcInternal.prx");
		//pModuleSystem->addAllowedFile("libScePad.prx");
		//pModuleSystem->addAllowedFile("libSceVideoOut.prx");
		//if (!bRet)
		//{
		//	break;
		//}

		bRet = true;
	} while (false);
	return bRet;

}
