// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "Comet.h"


// Sets default values
AComet::AComet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Comet"));
	RootComponent = Root;

	SpeedScale = 0.0f; 


}

// Called when the game starts or when spawned
void AComet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComet::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation();
	NewLocation.X += RunningTime * SpeedScale; 
	RunningTime += DeltaTime; 
	SetActorLocation(NewLocation); 


}

