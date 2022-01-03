// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractivePlatform.h"

#include "Components/BoxComponent.h"

// Sets default values
AInteractivePlatform::AInteractivePlatform()
{
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>("CollisionComponent");
	SetRootComponent(CollisionComponent);
}

// Called when the game starts or when spawned
void AInteractivePlatform::BeginPlay()
{
	Super::BeginPlay();
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AInteractivePlatform::OnSteppedUp);
}

void AInteractivePlatform::OnSteppedUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Red, FString::Printf(TEXT("Stepped on platform!")));
}