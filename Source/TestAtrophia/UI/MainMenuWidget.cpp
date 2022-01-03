// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "CreatorsWidget.h"
#include "SettingsWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::ToggleMenuBorderVisibility()
{
	if (MenuBorder->IsVisible())
	{
		MenuBorder->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		MenuBorder->SetVisibility(ESlateVisibility::Visible);
	}	
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	NewGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnClickedNewGameButton);
	SettingsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnClickedSettingsButton);
	CreatorsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnClickedCreatorsButton);
}

void UMainMenuWidget::OnClickedNewGameButton()
{
	GetGameInstance()->GetFirstLocalPlayerController()->SetInputMode(FInputModeGameOnly{});
	GetGameInstance()->GetFirstLocalPlayerController()->bShowMouseCursor = false;
	UGameplayStatics::OpenLevel(GetWorld(), NewLevelName);
}

void UMainMenuWidget::OnClickedCreatorsButton()
{	
	UCreatorsWidget* CreatorsWidget = WidgetTree->FindWidget<UCreatorsWidget>(CreatorsWidgetName);
	CreatorsWidget->SetVisibility(ESlateVisibility::Visible);
	MenuBorder->SetVisibility(ESlateVisibility::Hidden);
}

void UMainMenuWidget::OnClickedSettingsButton()
{		
	USettingsWidget* SettingsWidget = WidgetTree->FindWidget<USettingsWidget>(SettingsWidgetName);
	SettingsWidget->SetVisibility(ESlateVisibility::Visible);
	MenuBorder->SetVisibility(ESlateVisibility::Hidden);
}