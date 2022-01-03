// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatorsWidget.h"

#include "Components/Button.h"
#include "TestAtrophia/TestAtrophiaGameInstance.h"

void UCreatorsWidget::NativeConstruct()
{
	Super::NativeConstruct();
	BackButton->OnClicked.AddDynamic(this, &UCreatorsWidget::OnBackButtonClicked);
}

void UCreatorsWidget::OnBackButtonClicked()
{
	SetVisibility(ESlateVisibility::Hidden);
	UTestAtrophiaGameInstance* GameInstance = Cast<UTestAtrophiaGameInstance>(GetGameInstance());
	GameInstance->ToggleMenuVisibility();
}
