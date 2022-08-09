using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class JumpScript : MonoBehaviour {

	public float jumpForce;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown ("t")) {
			Jump ();
		}
		
	}

	void Jump() {
		Rigidbody body = this.GetComponent<Rigidbody> ();
		body.AddForce (new Vector3 (0, jumpForce, 0));
	}
}
