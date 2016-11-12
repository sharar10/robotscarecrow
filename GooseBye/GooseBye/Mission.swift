//
//  Mission.swift
//  GooseBye
//
//  Created by Kishan Patel on 11/11/16.
//  Copyright © 2016 Kishan Patel. All rights reserved.
//

import UIKit

class Mission {
    
    var name: String
    
    var sensitivity: Int
    
    init?(name: String, sensitivity: Int) {
        self.name = name
        self.sensitivity = sensitivity
        
        if name.isEmpty {
            return nil
        }
    }
    
}


