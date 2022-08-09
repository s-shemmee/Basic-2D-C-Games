using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ProjectileScript : MonoBehaviour {

	public float speedX = 100.0f;
	public float speedY = 0.1f;

	public float amplitude = 10;

	public float initialAngle = 30; // in degrees
	public float degrees;
	public float delta = 1.0f;


	// Use this for initialization
	void Start () {
		degrees = initialAngle;
	}

	// Update is called once per frame
	void Update () {
		// projectile update the horizontal and vertical position
		// Horizontal: linear equation
		// vertical: cos()
		float deltaY = Mathf.Cos(degrees * Mathf.Deg2Rad);
		degrees -= delta;
		float positionY = transform.position.y + deltaY;

		transform.position = new Vector3 (transform.position.x + speedX * Time.deltaTime,
			positionY,
			transform.position.z);
			
	}
}
