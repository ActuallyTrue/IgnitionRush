// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal", this, &APlayerCharacter::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &APlayerCharacter::VerticalMove);
	InputComponent->BindAxis("HorizontalRotation", this, &APlayerCharacter::HorizontalRot);
}

void APlayerCharacter::HorizontalRot(float value) {
	if (value) {
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}

void APlayerCharacter::HorizontalMove(float value) {
	if (value) {
		AddMovementInput(GetActorRightVector(), value);
	}
}

void APlayerCharacter::VerticalMove(float value) {
	if (value) {
		AddMovementInput(GetActorForwardVector(), value);
	}
}

