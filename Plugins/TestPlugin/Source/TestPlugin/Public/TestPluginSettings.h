// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestPluginSettings.generated.h"

/**
 * 
 */
UCLASS(Config = TestSettings)
class TESTPLUGIN_API UTestPluginSettings : public UObject
{
	GENERATED_BODY()

public:
	UTestPluginSettings(const FObjectInitializer& obj);

	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	int32 SomeIntProperty;
 
	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	bool SomeBoolProperty;

	UPROPERTY(Config, EditAnywhere, Category = "Other settings")
	FName PropertyName;
};
