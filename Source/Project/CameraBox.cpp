// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "CameraBox.h"
#include "kismet/GameplayStatics.h"

// Sets default values
ACameraBox::ACameraBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root4 = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root4->bGenerateOverlapEvents = true;
	Root4->OnComponentBeginOverlap.AddDynamic(this, &ACameraBox::MyOverlapFunction);
	RootComponent = Root4;
}

// Called when the game starts or when spawned
void ACameraBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraBox::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
void ACameraBox::MyOverlapFunction(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;


		APlayerController* OurPlayer = UGameplayStatics::GetPlayerController(this, 0);

		if (OurPlayer)
		{
			if ( CameraOne &&(OurPlayer->GetViewTarget() == CameraTwo))
			{
				OurPlayer->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
			}
			else if (CameraOne)
			{
				OurPlayer->SetViewTarget(CameraOne);
			}
		}
	
}