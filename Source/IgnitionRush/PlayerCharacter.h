// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "PhysicsPublic.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class IGNITIONRUSH_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector2D moveInput;

	void MovePlayer();

private:
	void HorizontalMove(float value);

	void VerticalMove(float value);

	void HorizontalRot(float value);

	void VerticalRot(float value);

	void CheckJump();

	UPROPERTY()
		bool jumping;

	UPROPERTY()
		UCameraComponent* cam;
	UPROPERTY()
		USpringArmComponent* arm;
};
