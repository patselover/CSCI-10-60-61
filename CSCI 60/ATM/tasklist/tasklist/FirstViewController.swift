//
//  FirstViewController.swift
//  tasklist
//
//  Created by Pat Selover on 6/16/16.
//  Copyright © 2016 Pat Selover. All rights reserved.
//

import UIKit

class FirstViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    //UITABLEVIEW Data Source
    public func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int{
        return taskMgr.tasks.count
    }
    public func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell{
        let cell: UITableViewCell = UITableViewCell(style:UITableViewCellStyle.Subtitle, reuseidentifier: "Defult")
        
        cell.text = taskMgr.tasks[indexPath.row].name
        cell.detailTextLabel= taskMgr.tasks[indexPath.row].des
        
        return cell
    }

}

