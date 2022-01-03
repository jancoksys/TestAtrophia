// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestPlugin.h"
#include "ISettingsModule.h"
#include "TestPluginSettings.h"

#define LOCTEXT_NAMESPACE "FTestPluginModule"

void FTestPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "TestPluginSettings",
			LOCTEXT("RuntimeSettingsName", "Atrophia test plugin"), LOCTEXT("RuntimeSettingsDescription", "Configure my setting"),
			GetMutableDefault<UTestPluginSettings>());
	}
}

void FTestPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if(ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "TestPluginSettings");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestPluginModule, TestPlugin)