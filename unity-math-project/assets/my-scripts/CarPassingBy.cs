using UnityEngine;
using System.Collections;

public class CarPassingBy : MonoBehaviour {

	AudioSource audioSource;
	public AudioClip clip;
	// Use this for initialization
	void Start () {
		audioSource = GetComponent<AudioSource> ();
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}


	void OnTriggerEnter(Collider other){
		if (other.gameObject.tag == "Player" ) {
			audioSource.PlayOneShot (clip);

		}
	}
}
