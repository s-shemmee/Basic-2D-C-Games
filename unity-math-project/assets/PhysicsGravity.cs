using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PhysicsGravity : MonoBehaviour {

	public Vector3 gravity;
	// Use this for initialization
	void Start () {
		Physics.gravity = gravity;
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
