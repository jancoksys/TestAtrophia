// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS(Abstract, NotBlueprintable)
class TESTATROPHIA_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	

	virtual void Interact();

	bool bHighlightObject = false;
	FVector GetBoxExtent() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Highlight")
	FVector BoxExtent = FVector::ZeroVector;
};
