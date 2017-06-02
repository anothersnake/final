// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "Asteroid2.h"


// Sets default values
AAsteroid2::AAsteroid2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	RootComponent = Root;

	SpeedScale = 0.0f;
	TimeDelay = 0.0f;

}

// Called when the game starts or when spawned
void AAsteroid2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsteroid2::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (DeltaTime > TimeDelay)
	{
		FVector NewLocation = GetActorLocation();
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		NewLocation.X += DeltaHeight * SpeedScale;
		RunningTime += DeltaTime;
		SetActorLocation(NewLocation);
	}
}

