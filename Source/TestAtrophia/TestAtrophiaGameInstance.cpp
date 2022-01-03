// Fill out your copyright notice in the Description page of Project Settings.


#include "TestAtrophiaGameInstance.h"
#include "UI/MainMenuWidget.h"

void UTestAtrophiaGameInstance::OpenMainMenu()
{
	if (!IsValid(MainMenuWidget))
	{
		MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);		
	}	
	MainMenuWidget->AddToViewport();

	GetFirstLocalPlayerController()->SetInputMode(FInputModeUIOnly{});
	GetFirstLocalPlayerController()->bShowMouseCursor = true;
}

void UTestAtrophiaGameInstance::ToggleMenuVisibility()
{
	if (!IsValid(MainMenuWidget))
	{
		return;
	}
	MainMenuWidget->ToggleMenuBorderVisibility();
}
