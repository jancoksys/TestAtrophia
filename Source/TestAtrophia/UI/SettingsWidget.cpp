// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsWidget.h"

#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "TestAtrophia/TestAtrophiaGameInstance.h"

void USettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	BackButton->OnClicked.AddDynamic(this, &USettingsWidget::OnBackButtonClicked);
}

void USettingsWidget::OnBackButtonClicked()
{
	SetVisibility(ESlateVisibility::Hidden);
	UTestAtrophiaGameInstance* GameInstance = Cast<UTestAtrophiaGameInstance>(GetGameInstance());
	GameInstance->ToggleMenuVisibility();
}
