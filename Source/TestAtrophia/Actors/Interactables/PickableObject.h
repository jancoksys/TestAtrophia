// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PickableObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TESTATROPHIA_API APickableObject : public AInteractableActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
