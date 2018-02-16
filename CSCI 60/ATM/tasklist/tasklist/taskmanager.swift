//
//  taskmanager.swift
//  tasklist
//
//  Created by Pat Selover on 6/16/16.
//  Copyright © 2016 Pat Selover. All rights reserved.
//

import Cocoa
import UIKit
var taskMgr : TaskManager = TaskManager()

struct task{
    var name = "unnamed"
    var desc = "undescribed"
}
class taskmanager: NSObject {
    var tasks = task[]()
    
    func addTask(name:String, desc:String){
        tasks.append(task(name: name, desc: desc))
    }
}
