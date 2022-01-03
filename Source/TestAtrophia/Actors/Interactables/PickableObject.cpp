// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableObject.h"

void APickableObject::BeginPlay()
{
	Super::BeginPlay();
	bHighlightObject = true;
}
