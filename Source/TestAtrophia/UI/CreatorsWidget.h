// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreatorsWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTATROPHIA_API UCreatorsWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton;

	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnBackButtonClicked();
};
