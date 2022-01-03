// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"


class UButton;
class UCreatorsWidget;
class USettingsWidget;

UCLASS()
class TESTATROPHIA_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void ToggleMenuBorderVisibility();

protected:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UCreatorsWidget> CreatorsWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<USettingsWidget> SettingsWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Level")
	FName NewLevelName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget names")
	FName CreatorsWidgetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget names")
	FName SettingsWidgetName;

	UPROPERTY(meta = (BindWidget))
	UButton* NewGameButton;	

	UPROPERTY(meta = (BindWidget))
	UButton* CreatorsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SettingsButton;

	UPROPERTY(meta = (BindWidget))
	class UBorder* MenuBorder;

	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnClickedNewGameButton();

	UFUNCTION()
	void OnClickedCreatorsButton();

	UFUNCTION()
	void OnClickedSettingsButton();	
};

