// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();
	originalLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if(shouldMove) {
		Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		FVector currentLocation = GetOwner()->GetActorLocation();
		FVector targetLocation = originalLocation + moveOffset;
		float speed = FVector::Distance(originalLocation, targetLocation)/duration;

		FVector newLocation = FMath::VInterpConstantTo(currentLocation, targetLocation, DeltaTime, speed);

		GetOwner()->SetActorLocation(newLocation);
	}



	/*
	AActor* owner = GetOwner();

	FString name = owner->GetActorNameOrLabel();
	FString location = owner->GetActorLocation().ToCompactString();

	UE_LOG(LogTemp, Display, TEXT("Mover Owner: %s"), *name);

	UE_LOG(LogTemp, Display, TEXT("Mover Owner Location: %s"), *location);
	*/

}

