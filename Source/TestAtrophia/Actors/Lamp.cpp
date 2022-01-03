// Fill out your copyright notice in the Description page of Project Settings.


#include "Lamp.h"
#include "Components/CapsuleComponent.h"
#include "Components/PointLightComponent.h"

ALamp::ALamp()
{
	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>("CollisionComponent");
	SetRootComponent(CollisionComponent);

	LightComponent = CreateDefaultSubobject<UPointLightComponent>("LightComponent");
	LightComponent->SetupAttachment(RootComponent);	
}

void ALamp::BeginPlay()
{
	Super::BeginPlay();
	LightComponent->SetVisibility(false);
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ALamp::OnOverlappedCollision);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ALamp::OnEndOverlap);
}

void ALamp::OnOverlappedCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	LightComponent->SetVisibility(true);
}

void ALamp::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	LightComponent->SetVisibility(false);
}
