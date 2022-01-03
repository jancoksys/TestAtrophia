// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TestAtrophiaGameInstance.generated.h"

class USettingsWidget;
class UCreatorsWidget;
class UMainMenuWidget;
/**
 * 
 */
UCLASS()
class TESTATROPHIA_API UTestAtrophiaGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void OpenMainMenu();

	void ToggleMenuVisibility();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UMainMenuWidget> MainMenuWidgetClass;

private:
	UMainMenuWidget* MainMenuWidget;
};