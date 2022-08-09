using UnityEngine;
using System.Collections;

public class VehicleCollision : MonoBehaviour {

	public AudioSource audioSource;
	public AudioClip clip;
	// Use this for initialization
	void Start () {
		audioSource = GetComponent<AudioSource> ();
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnTriggerEnter(Collider other){
		if (other.gameObject.tag == "Player") {
			PlayerHealth playerHealth = other.gameObject.GetComponent<PlayerHealth>();
			playerHealth.Death ();
			audioSource.PlayOneShot (clip);
		} else if (other.gameObject.tag == "Enemy") {
			EnemyHealth enemyHealth = other.gameObject.GetComponent<EnemyHealth> ();
			enemyHealth.Death ();
			audioSource.PlayOneShot (clip);

		}
	}
}
