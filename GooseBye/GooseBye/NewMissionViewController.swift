//
//  NewMissionViewController.swift
//  GooseBye
//
//  Created by Kishan Patel on 11/12/16.
//  Copyright © 2016 Kishan Patel. All rights reserved.
//

import UIKit

class NewMissionViewController: UIViewController, UITextFieldDelegate {
    
    var mission: Mission?

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
        nameTextField.delegate = self
        sensitivityTextField.delegate = self
        
        if let mission = mission {
            navigationItem.title = mission.name
            nameTextField.text = mission.name
            sensitivityTextField.text = mission.sensitivity
        }
        
        checkValidMissionName()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBOutlet weak var nameTextField: UITextField!
    
    @IBOutlet weak var sensitivityTextField: UITextField!

    @IBOutlet weak var saveButton: UIBarButtonItem!
    
    @IBAction func cancelPress(_ sender: UIBarButtonItem) {
        let isPresentingInAddMissionMode = presentingViewController is UINavigationController
        if isPresentingInAddMissionMode {
            dismiss(animated: true, completion: nil)
        }
        else {
            navigationController?.popViewController(animated: true)
        }
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        saveButton.isEnabled = false
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        checkValidMissionName()
        let text = nameTextField.text ?? ""
        if !text.isEmpty {
            navigationItem.title = nameTextField.text
        }
        else {
            navigationItem.title = "New Mission"
        }
    }
    
    func checkValidMissionName() {
        let text = nameTextField.text ?? ""
        saveButton.isEnabled = !text.isEmpty
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if saveButton === sender as AnyObject {
            let name = nameTextField.text ?? ""
            let sensitivity = sensitivityTextField.text
            mission = Mission(name: name, sensitivity: sensitivity)
        }
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
