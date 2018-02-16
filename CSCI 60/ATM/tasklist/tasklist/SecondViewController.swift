//
//  SecondViewController.swift
//  tasklist
//
//  Created by Pat Selover on 6/16/16.
//  Copyright © 2016 Pat Selover. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController, UITextFieldDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        self.view.endEditing(true)
    }
    
    //uitextfielddelegate
    func textFieldShouldReturn(textField: UITextField) -> Bool{
        textField.resignFirstResponder();
        return true
    }

}

