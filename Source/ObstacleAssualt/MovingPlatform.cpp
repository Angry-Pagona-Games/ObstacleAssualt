// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


		//Move Platform Forward
		//Get Curret Location
	FVector CurrentLocation = GetActorLocation();

		//Add Vector to Current Location
	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
	
		//Set the New Location/
	SetActorLocation(CurrentLocation);
	
		/*Send Platform Back if it has gone too far*/
		//Check how far platform has moved
	float DistanceMoved = FVector :: Dist(StartLocation, CurrentLocation);
		//Reverse direction of motion if platform moves to far
	if (DistanceMoved > MoveDistance)
	{
			
			FVector MoveDirection = PlatformVelocity.GetSafeNormal();
			StartLocation = StartLocation + MoveDirection * MoveDistance;
			SetActorLocation(StartLocation);
			PlatformVelocity = -PlatformVelocity;

	}
	
	
	

}

