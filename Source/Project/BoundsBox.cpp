// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "BoundsBox.h"


// Sets default values
ABoundsBox::ABoundsBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root1->bGenerateOverlapEvents = true; 
	Root1->OnComponentBeginOverlap.AddDynamic(this, &ABoundsBox::MyOverlapFunction); 
	RootComponent = Root1;


}

// Called when the game starts or when spawned
void ABoundsBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoundsBox::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
void ABoundsBox::MyOverlapFunction(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtherActor->SetActorLocation(StartingLocation); 
}
