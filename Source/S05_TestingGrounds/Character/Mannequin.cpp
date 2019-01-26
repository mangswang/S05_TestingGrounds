// Fill out your copyright notice in the Description page of Project Settings.

#include "Mannequin.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Weapons/Gun.h"
#include "Classes/Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AMannequin::AMannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterFPMesh"));
	FPMesh->SetOnlyOwnerSee(true);
	FPMesh->SetupAttachment(FirstPersonCameraComponent);
	FPMesh->bCastDynamicShadow = false;
	FPMesh->CastShadow = false;
	FPMesh->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	FPMesh->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);
}


// Called when the game starts or when spawned
void AMannequin::BeginPlay()
{
	Super::BeginPlay();
	if (GunBlueprint == NULL) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint missing."));
		return;
	}
	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);
	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	if (IsPlayerControlled())
	{
		Gun->AttachToComponent(FPMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint")); 
		Gun->AnimInstanceFP = FPMesh->GetAnimInstance();
	}
	else
	{
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		Gun->AnimInstanceTP = GetMesh()->GetAnimInstance();
	}
	/*if (InputComponent != NULL)
	{
		InputComponent->BindAction("PullTrigger", IE_Pressed, this, &AMannequin::PullTrigger);
	}*/
}

// Called every frame
void AMannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("PullTrigger", IE_Pressed, this, &AMannequin::PullTrigger);
}

void AMannequin::UnPossessed()
{
	Super::UnPossessed();
	if (Gun != nullptr)
	{
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	}
}

void AMannequin::PullTrigger()
{
	if (Gun != NULL)
	{
		Gun->OnFire();
	}
}

void AMannequin::GetActorEyesViewPoint(FVector & Location, FRotator & Rotation) const
{
	GetPerceptionLocRot(Location, Rotation);
}

void AMannequin::GetPerceptionLocRot_Implementation(FVector & OutLocation, FRotator & OutRotation) const
{
	OutLocation = GetActorLocation() + FVector(0, 0, 50);
	OutRotation = GetActorRotation();

}
