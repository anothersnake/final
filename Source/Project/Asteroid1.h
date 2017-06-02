// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Asteroid1.generated.h"

UCLASS()
class PROJECT_API AAsteroid1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroid1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
	UShapeComponent* Root; 

	UPROPERTY(EditAnywhere)
		float SpeedScale ; 
 
	UPROPERTY(EditAnywhere)
		float TimeDelay; 

	float RunningTime; 
	
};
